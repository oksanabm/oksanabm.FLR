#include "ourClass.h"
ofstream out_criterion("criterion.txt");
//конструктор
method::method()
{
    y_main = NULL;
    y_oc = NULL;
    x_var = NULL;
    x_two = NULL;
}

//деструктор
method::~method()
{
    void clear();
}
//функция очистки
void method::clear()
{
    if(x_var)
    {
        delete [] x_var;
        x_var = NULL;
    }

    if(x_two)
    {
        for(int i = 0; i < inData.dimExp; i++)
            delete [] x_two[i];
        delete [] x_two;
        x_var = NULL;
    }
    if(y_main)
    {
        delete [] y_main;
        y_main = NULL;
    }
    if(y_oc)
    {
        delete [] y_oc;
        y_oc = NULL;
    }
}

//генератор случайных чисел по равномерному закону
double clustering::generationNumberRAV(double min,double max)
{
    double alpha1 = rand() / (double)RAND_MAX;
    double randNumber = min + alpha1*(max - min);
    return randNumber;
}

//выделение памяти, установка начальных данных для кластеризации и т.д.
void clustering::newData()
{
    mu_summ1 = 0; mu_summ2 = 0;
    summ = 0.0;

    v = new double*[Nc];
    x = new double*[N];
    d = new double*[N];
    tmp_d = new double*[N];
    rez_mult_X_V = new double*[dim];
    difference_X_V = new double*[1];
    difference_X_V[0] = new double[dim];
    difference_X_V_matrix = new double*[N];
    tmp_numerator_formula = new double*[dim];
    tmp_numerator_formula2 = new double*[dim];
    dop_sum1 = new double[N];
    dop_sum2 = new double[N];
    mu_prev = new double*[N];
    mu_prev_transp = new double*[Nc];
    mu_next = new double*[N];
    mult_X_V = new double*[N];
    rez_mult_mu_XV = new double*[dim];
    cov_matrix_obr = new double*[dim];

    for(int i=0; i<N; i++){
        x[i] = new double[dim];
        d[i] = new double[Nc];
        tmp_d[i] = new double[Nc];
        mu_prev[i]=new double[Nc];
        mu_next[i]=new double[Nc];
        mult_X_V[i]=new double[N];
        difference_X_V_matrix[i] = new double[dim];
        dop_sum1[i] = 0.0;
        dop_sum2[i] = 0.0;
    }

    for(int i=0; i<Nc; i++){
        mu_prev_transp[i] =new double[N];
        v[i] = new double[dim];
    }

    for (int i=0; i<N; i++)
        for (int k = 0; k<Nc; k++){
                mu_prev[i][k] = 0.0;
                mu_prev_transp[k][i] = 0.0;
                mu_next[i][k] = 0.0;
                d[i][k] = 0.0;
                tmp_d[i][k] = 0.0;
        }

    for (int i=0; i<N; i++)
        for (int k = 0; k<dim; k++){
            x[i][k] = 0.0;
            difference_X_V_matrix[i][k] = 0.0;}

    for (int k = 0; k<dim; k++)
        difference_X_V[0][k] = 0.0;

    for (int i=0; i<Nc; i++)
        for (int k = 0; k<dim; k++)
            v[i][k] = 0.0;

        A_inv = new double * [N];
    for(int i = 0; i < N; i++)
        A_inv[i] = new double [N];

    for (int i=0; i<N; i++)
        for (int k = 0; k<N; k++){
            mult_X_V[i][k] = 0.0;
            A_inv[i][k] = 0.0;
        }

    for (int i = 0; i<dim; i++){
        rez_mult_mu_XV[i]=new double[dim];
        rez_mult_X_V[i]=new double[dim];
        cov_matrix_obr[i] = new double[dim];
        tmp_numerator_formula[i] = new double[dim];
        tmp_numerator_formula2[i] = new double[dim];}




    tmp.resize(dim);
    distance.resize(N);
    tmp_for_dist.resize(N);
    distance.push_back(0.0);
    tmp.push_back(0.0);
    v_cov_matrix.resize(Nc);
    v_scale_matrix.resize(Nc);

    cov_matrix.resize(dim);
    scale_matrix.resize(dim);

    for (int i = 0; i < dim; i++)
    {
        cov_matrix[i].resize(dim);
        scale_matrix[i].resize(dim);
    }


    for (int i = 0; i<dim; i++)
        for (int k = 0; k<dim; k++){
            rez_mult_X_V[i][k] = 0.0;
            rez_mult_mu_XV[i][k] = 0.0;
            cov_matrix[i][k] = 0.0;
            scale_matrix[i][k] = 0.0;
            cov_matrix_obr[i][k] = 0.0;
            tmp_numerator_formula[i][k] = 0.0;
            tmp_numerator_formula2[i][k] = 0.0;
        }

    vector_matrix_distance.resize(N);
    for (int i = 0; i < N; i++)
        vector_matrix_distance[i].resize(Nc);
}


//подсчет начальной матрицы принадлежности
void clustering::begin_U()
{
    for (int i=0; i<N; i++)//по всем строкам матрицы
    {
        for (int k = 0; k<Nc; k++){
                mu_prev[i][k] = generationNumberRAV(0, 1);
                dop_sum1[i] += mu_prev[i][k];}

        for (int k = 0; k<Nc; k++)
            mu_prev[i][k] = mu_prev[i][k]/dop_sum1[i];//в сумме строки должна быть 1ца
    }

    /*cout << "mu_prev:" << endl;
    for (int i=0; i<N; i++){
        for (int k = 0; k<Nc; k++){
            printf("%.16lf\t", mu_prev[i][k]);
        }//выводим матрицу
        cout << endl;}
    cout << endl;*/
}

//подсчет центров кластеров
void clustering::centerCluster()
{
    if (dim == 1)
    {
        for (int k=0; k<Nc; k++)//по всем кластерам
        {
            for(int j=0; j<dim; j++)//по всем факторам
            {
                for (int i=0; i<N; i++)//по всем точкам
                {
                    mu_summ1 += pow(mu_prev[i][k], (double)w) * x[i][j];
                    mu_summ2 += pow(mu_prev[i][k], (double)w);
                }
                v[k][j] = mu_summ1/mu_summ2;
                mu_summ1 = 0.0; mu_summ2 = 0.0;
            }
        }
    }
    else
    {
        for (int k=0; k<Nc; k++)//по всем кластерам
        {
            for(int j=0; j<dim; j++)//по всем факторам
            {
                mu_summ1 = 0.0; mu_summ2 = 0.0;

                for (int i=0; i<N; i++){//по всем точкам
                    mu_summ1 += pow(mu_prev[i][k], (double)w) * x[i][j];//для одного фактора
                    mu_summ2 += pow(mu_prev[i][k], (double)w);}

                v[k][j] = mu_summ1/mu_summ2;
            }

        }

    }

    cout << "\ncenters clusters\n";
    for (int k=0; k<Nc; k++){
        for(int j=0; j<dim; j++)
            cout << v[k][j] << "\t";
        cout << endl;}
}

//подсчет расстояния для FCM
void clustering::distanse_fcm()
{
    if (dim == 1)
    {
    for (int i=0; i<N; i++)
        for (int k = 0; k<Nc; k++)
                d[i][k] = fabs(x[i][0] - v[k][0]);

        /*cout << "d:" << endl;
        for (int i=0; i<N; i++)
        {
            for (int k = 0; k<Nc; k++)
                printf("%.16lf\t", d[i][k]);
            cout << endl;
        }*/
    }
    else
    {
        for (int i=0; i<N; i++)
        {
            for (int k = 0; k<Nc; k++){

                for (int j = 0; j<dim; j++)
                    tmp[j] = x[i][j] - v[k][j];//складываем в вектор разницу по всем координатам

                for (int j = 0; j<dim; j++)//складываем квадраты всех координат
                    tmp_d[i][k] += tmp[j] * tmp[j];

                d[i][k] = sqrt(tmp_d[i][k]);//корень из суммы квадратов всех координат
            }

            tmp.assign (tmp.size(), 0);

            for (int p=0; p<N; p++)
                for (int l = 0; l<Nc; l++)
                    tmp_d[p][l] = 0.0;
        }

        /*cout << "d:" << endl;
        for (int i=0; i<N; i++){
        {
            for (int k = 0; k<Nc; k++)
                printf("%.16lf\t", d[i][k]);
            cout << endl;
        }
        }*/
    }
}

//подсчет новой матрицы U для FCM
void clustering::Mu_Calc_fcm()
{
    summ = 0.0;
    double one=0.0, two=0.0;
    for (int k=0; k<Nc; k++)
        for (int i = 0; i<N; i++)
        {
            for (int j=0; j<Nc; j++)
                {
                        one = d[i][k];
                        two = d[i][j];
                        summ += pow( one/two, 2.0/((double)(w-1) ));}
                mu_next[i][k] = 1/(double)summ;
                summ = 0.0;
        }

    /*cout << "mu_next:" << endl;
    for (int i=0; i<N; i++){
        for (int k = 0; k<Nc; k++){
            printf("%.16lf\t", mu_next[i][k]);}//выводим матрицу
        cout << endl;}
    cout << endl;*/
}

//подсчет ковариационной матрицы
void clustering::matrix_covariance_GK()
{
    double summ_one = 0.0, summ_two = 0.0;
    mu_sum = 0.0, ch = 0.0;

    for(int p=0; p<Nc; p++)//ГЛОБАЛЬНЫЙ ЦИКЛ ПО КЛАСТЕРАМ
    {
        for(int i=0; i<N; i++)//по всем наблюдениям
        {
            //считаем расстояние от точки Х до чентра кластера (несколько координат)
            for (int k=0; k<dim; k++)
                difference_X_V[0][k] = x[i][k] - v[p][k];//строка их двух координат

            //перемножение вектора на вектор транспонированный-----------
            for (int k=0; k<dim; k++)
                for (int l=0; l<dim; l++)
                    rez_mult_X_V[k][l] = difference_X_V[0][k] * difference_X_V[0][l];

            //умножение на мю---------------------------------------------
            for (int k=0; k<dim; k++)
                for (int l=0; l<dim; l++)
                    rez_mult_mu_XV[k][l] = pow(mu_prev[i][p], (double)w) * rez_mult_X_V[k][l];

            //суммируем матрицу каждого кластера S_i
            for (int k=0; k<dim; k++)
                for (int l=0; l<dim; l++)
                    tmp_numerator_formula[k][l] += rez_mult_mu_XV[k][l];

        }//по наблюдениям

        //знаменатель
        for(int i=0; i<N; i++)
            mu_summ1 += pow(mu_prev[i][p], (double)w);

        for (int k=0; k<dim; k++)
                for (int l=0; l<dim; l++)
                    tmp_numerator_formula2[k][l] = tmp_numerator_formula[k][l]/mu_summ1;

        mu_summ1 = 0.0;

        for (int k = 0; k<dim; k++)
            for (int l = 0; l<dim; l++)
                cov_matrix[k][l] = tmp_numerator_formula2[k][l];

        v_cov_matrix[p] = cov_matrix;

            //обнуляем все данные для подсчета по следующему наблюдению
            for (int k=0; k<dim; k++)
                for (int l=0; l<dim; l++){
                    difference_X_V[0][k] = 0.0;
                    rez_mult_X_V[k][l] = 0.0;
                    rez_mult_mu_XV[k][l] = 0.0;
                    tmp_numerator_formula[k][l] = 0.0;
                    cov_matrix[k][l] = 0.0;
                    tmp_numerator_formula2[k][l] = 0.0;}
    mu_summ1 = 0.0;
    }//по кластерам

    cout << "\ncov_matrix:" << endl;
    for (int p = 0; p<Nc; p++){
        printf("%d cluster\n", p+1);
        for (int i = 0; i<dim; i++)
        {
            for (int k = 0; k<dim; k++)
                printf("\t%.16lf\t", v_cov_matrix[p][i][k]);
            cout << endl;
        }
    cout << endl;
    }
}

//подсчет определителя ковариационной матрицы
double clustering::det_matrix_covariance_GK(vector<vector<double>> mas_for_determinant, int dimention)
{
    double dd;
    int i,j,k,n;
    double **p;

    p = new double*[dimention];

    for(i=0; i<dimention; i++)
        p[i] = new double[dimention];

    j = 0; dd = 0;
    k = 1; //(-1) в степени i
    n = dimention - 1;

    if (dimention < 1)
        {cout << "Определитель вычислить невозможно!";}

    if (dimention == 1)
    {
        dd = mas_for_determinant[0][0];

        return (dd);
    }
    if (dimention == 2)
    {
        dd = mas_for_determinant[0][0]*mas_for_determinant[1][1]-(mas_for_determinant[1][0]*mas_for_determinant[0][1]);

        return(dd);
    }

    if (dimention == 3)
    {
        dd = mas_for_determinant[0][0]*mas_for_determinant[1][1]*mas_for_determinant[2][2] + mas_for_determinant[0][1]*mas_for_determinant[1][2]*mas_for_determinant[2][0] + mas_for_determinant[0][2]*mas_for_determinant[1][0]*mas_for_determinant[2][1] - mas_for_determinant[0][2]*mas_for_determinant[1][1]*mas_for_determinant[2][0] - mas_for_determinant[0][0]*mas_for_determinant[1][2]*mas_for_determinant[2][1] - mas_for_determinant[0][1]*mas_for_determinant[1][0]*mas_for_determinant[2][2];

        return(dd);
    }

    if (dimention > 3)
    {
        for (i=0; i<dimention; i++) {
            GetMatr(mas_for_determinant, p, i, 0, dimention);
            dd = dd + k * mas_for_determinant[i][0] * det_matrix_covariance_GK(mas_for_determinant, n);
            k=-k;
        }
    return dd;
    }

}

// Получение матрицы без i-й строки и j-го столбца
void clustering::GetMatr(vector<vector<double>> mas, double **p, int i, int j, int m)
{
    int ki,kj,di,dj;
    di=0;

    for(ki=0;ki<m-1;ki++) { // проверка индекса строки
        if (ki==i)  di=1;
        dj=0;

        for(kj=0;kj<m-1;kj++) { // проверка индекса столбца
            if (kj==j)  dj=1;
            p[ki][kj]=mas[ki+di][kj+dj];
        }
    }
}

//подсчет матрицы масштаба
void clustering::matrix_scale_GK()
{
    double d, tmp_number;
    for (int p=0; p<Nc; p++)//ПО КАЖДОМУ КЛАСТЕМУ БУДЕТ СВОЯ МАТРИЦА
    {
        d = 0.0;
        d_in_pow = 0.0;
        tmp_number = 0.0;

        //считаем определитель матрицы
        d = det_matrix_covariance_GK(v_cov_matrix[p], dim);

        //возводим в степень
        d_in_pow = pow(d, 1.0/(double)N);
        printf("\n d = %.16lf\n", d_in_pow);

        //обращаем матрицу ковариации
        cov_matrix_obr = PseudoInverse_cluster(v_cov_matrix[p], dim);

    printf("\nInvers_matrix for %d cluster:\n", p+1);
    for (int i = 0; i<dim; i++)
    {
        for (int k = 0; k<dim; k++)
            printf("\t%.16lf\t", cov_matrix_obr[i][k]);
        cout << endl;
    }

        //считаем саму матрицу масштаба
        for (int i=0; i<dim; i++)
            for (int j=0; j<dim; j++)
                scale_matrix[i][j] = d * cov_matrix_obr[i][j];

    printf("\nscale_matrix for %d cluster:\n", p+1);
        for (int i = 0; i<dim; i++)
        {
            for (int k = 0; k<dim; k++)
                printf("\t%.16lf\t", scale_matrix[i][k]);
            cout << endl;
        }

        //складываем в вектор матриц
        v_scale_matrix[p] = scale_matrix;

        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                A_inv[i][j] = 0.0;
    }

    for (int k=0; k<dim; k++)
        for (int l=0; l<dim; l++){
            scale_matrix[k][l] = 0.0;
            cov_matrix_obr[k][l] = 0.0;
        }
}

vector<double> clustering::mult_difference_X_V_matrix_v_scale_matrix(int number_cluster)
{
    double **temp1, **temp3;
    temp1 = new double*[N];
    temp3 = new double*[dim];

    for (int k = 0; k < N; k++)
        temp1[k] = new double[dim];

    for (int k = 0; k<dim; k++)
        temp3[k] = new double[dim];

    for (int i = 0; i < N; i++)
        for (int k = 0; k<dim; k++){
            temp1[i][k] = 0.0;
            distance[i] = 0.0;
    }

    for (int i = 0; i < dim; i++)
        for (int k = 0; k<dim; k++)
            temp3[i][k] = 0.0;

    for (int k = 0; k<dim; k++)
        for (int l = 0; l<dim; l++)
            temp3[k][l] = v_scale_matrix[number_cluster][k][l];

    for( int i=0; i<N; i++ )
            for (int k=0; k<dim; k++){
                for (int l=0; l<dim; l++)
                    temp1[i][k] += difference_X_V_matrix[i][l] * temp3[k][l];

                for (int l=0; l<dim; l++)
                    distance[i] += temp1[i][l] * difference_X_V_matrix[i][l];
            }

    for (int i = 0; i < N; i++)
        delete[] temp1[i];

    for (int i = 0; i < dim; i++)
        delete[] temp3[i];

    delete[] temp1;
    delete[] temp3;

    return distance;
}

//расстояния Густафсона-Кесселя
void clustering::distance_GK()
{
    for (int p=0; p<Nc; p++)//формируется столбец расстояний по каждому кластеру
    {
        //считаем расстояние от точки Х до чентра кластера (несколько координат)
        for (int i=0; i<N; i++)
            for (int k=0; k<dim; k++)
                difference_X_V_matrix[i][k] = x[i][k] - v[p][k];//строка их двух координат

        tmp_for_dist = mult_difference_X_V_matrix_v_scale_matrix(p);//ВОЗВРАЩАЕТСЯ ВЕКТООООООООООР, как в матрицу на р-ый столбец поместить этот вектор?

        for (int i=0; i<N; i++)
            vector_matrix_distance[i][p] = tmp_for_dist[i];

        for (int k=0; k<N; k++)
            for (int l=0; l<dim; l++)
                difference_X_V_matrix[k][l] = 0.0;

    }
    cout << "\nd:" << endl;
    for (int i = 0; i<N; i++){
        for (int k = 0; k<Nc; k++)
            printf("%.16lf\t", vector_matrix_distance[i][k]);
    printf("\n");
    }
}

//обращение матрицы ковариации
double **clustering::PseudoInverse_cluster(vector<vector<double>> A, int N)
{
    // A - это U
    double ** U = new double * [N];
    for(int i = 0; i < N; i++)
    {
        U[i] = new double [N];
        for(int j = 0; j < N; j++)
            U[i][j] = A[i][j];
    }

    double ** V = new double * [N];
    for(int i = 0; i < N; i++)
        V[i] = new double [N];

    double * W = new double [N];

    svdcmp_cluster(U, N, N, W, V);


    // Поиск эпсилон
    double max_w = W[0];
    for(int i = 1; i < N; i++)
        if(fabs(W[i]) > max_w) max_w = fabs(W[i]);
    double epsilon = DBL_EPSILON * max_w * N;

    // Поиск W+
    for(int i = 0; i < N; i++)
    {
        if(W[i] > epsilon)
            W[i] = 1.0 / W[i];
        else
            W[i] = 0.0;
    }

    // Поиск V * W+
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            V[i][j] *= W[j];

    // Поиск V * W+ * U*
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            A_inv[i][j] = 0.0;
            for(int k = 0; k < N; k++)
            {
                A_inv[i][j] += V[i][k] * U[j][k];
            }
        }

    // Чистим память
    for(int i = 0; i < N; i++)
    {
        delete [] U[i];
        delete [] V[i];
    }
    delete [] U;
    delete [] V;
    delete [] W;

    return A_inv;
}

//подсчет матрицы принадлежности
void clustering::Mu_Calc_GK()
{
    double **temp1;
    temp1 = new double*[N];

    for (int k = 0; k < N; k++)
        temp1[k] = new double[Nc];

    for (int i = 0; i < N; i++)
        for (int k = 0; k < Nc; k++)
            temp1[i][k] = 0.0;

    for (int i = 0; i < N; i++)
        for (int k = 0; k < Nc; k++)
            temp1[i][k] = vector_matrix_distance[i][k];

    summ = 0.0;
    double one=0.0, two=0.0;
    for (int i=0; i<Nc; i++)
        for (int k = 0; k<N; k++)
        {
            for (int j=0; j<Nc; j++){
                one = temp1[k][i];
                two = temp1[k][j];
                summ += pow(one/two,2.0/((double)(w-1)));}
        mu_next[k][i] = 1/(double)summ;
        summ = 0.0;
        }

    for (int i = 0; i < N; i++)
        delete[] temp1[i];

    delete[] temp1;
}


//функция проверки вхождения точки в отрезок
bool sector::in_sector(double x)
{
    return (x >= a) && (x <= b);//для одномерного случая, когда 1 фактор, проверяем вхождение в отрезок
}

//функция проверки вхождения отрезка в прямоугольник
bool rectangle::in_rect(double* x)
{
    return (x[0] >= a[0]) && (x[0] <= b[0]) && (x[1] >= a[1]) && (x[1] <= b[1]);//для двумерного случая - когда два фактора
}

//функция определения номера для одномерного случая
int sector::mu_number_one(int i, int j, int choiceFunc, int **mu_loc_number)
{
    int point_number;
    if (choiceFunc == 1) {//если треугольники
        switch(i)
        {
        //case 0: point_number = mu_loc_number[j][0]; break;
        //case 1: point_number = mu_loc_number[j][1]; break;
        case 0: point_number = number_a; break;
        case 1: point_number = number_a + 1;
        }
    }
    else {//если трапеции
        switch(i)
        {
        case 0: point_number = mu_loc_number[j][0]; break;
        case 1: point_number = mu_loc_number[j][0]; break;
        case 2: point_number = mu_loc_number[j][1];
        };
    }
    return point_number;
}

//функция определения номера для двумерного случая
int rectangle::mu_number_two(int i, int j, int choiceFunc, int **mu_loc_number_x, int **mu_loc_number_y) {
    int point_number;

    switch(i) {
    case 0: point_number = n_x * number_a[1] + number_a[0]; break;
    case 1: point_number = n_x * number_a[1] + number_a[0] + 1; break;
    case 2: point_number = n_x * (number_a[1]+1) + number_a[0]; break;
    case 3: point_number = n_x * (number_a[1]+1) + number_a[0] + 1;
    }
    return point_number;
}

//значение функции принадлежности в точке х (ДЛЯ ТРЕУГОЛЬНИКОВ) для одномерного
double sector::mu_val_tri_one(int i, double x)
{
    double X1 = (b - x) / (b - a);//правая часть треугольника
    double X2 = (x - a) / (b - a);//левая часть треугольника

    switch(i)
    {
    case 0: return X1; break;
    case 1: return X2;
    }
}

//значение функции принадлежности в точке х (ДЛЯ ТРЕУГОЛЬНИКОВ) для двумерного
double rectangle::mu_val_tri_two(int i, double* x)
{
    double X1 = (b[0] - x[0]) / (b[0] - a[0]);//правая часть треугольника
    double X2 = (x[0] - a[0]) / (b[0] - a[0]);//левая часть треугольника
    double Y1 = (b[1] - x[1]) / (b[1] - a[1]);
    double Y2 = (x[1] - a[1]) / (b[1] - a[1]);

    switch(i)
    {
    case 0: return X1 * Y1;
    case 1: return X2 * Y1;
    case 2: return X1 * Y2;
    case 3: return X2 * Y2;
    }
}

//значение функции принадлежности в точке х (ДЛЯ ТРАПЕЦИЙ) для одномерного
double sector::mu_val_tra_one(int i, double x)
{
    double X1 = 1.0;//верхнеее основание трапеции
    double X2 = (b - x) / (b - a);//правая часть треугольника
    double X3 = (x - a) / (b - a);//левая часть треугольника

    switch(i)
    {
    case 0: return X1;
    case 1: return X2;
    case 2: return X3;
    }
}


//генератор случайных чисел по равномерному закону
double method::generationNumberRAV(double min,double max)
{
    double alpha1 = rand() / (double)RAND_MAX;
    double randNumber = min + alpha1*(max - min);
    return randNumber;
}

//генератор с.в. по нормальному закону при помощи преобразования Бокса-Мюллера
double method::generationNumberNORMAL(double mathWait, double sigma2)
{
    double alpha1 = rand() / (double)RAND_MAX;
    double alpha2 = rand() / (double)RAND_MAX;
    double ksi = sqrt(-2.0 * log(alpha1)) * cos(2.0 * 3.14159 * alpha2);
    return mathWait + sqrt(sigma2) * ksi;
}

//инициализатор для одномерного случая
void method::initialization_one()
{
    x_var = new double*[inData.dimExp];//одномерный массив иксов(строк)
    y_main = new double[inData.dimExp];//двумерный массив отклика
    Xmat = new double*[inData.dimExp];//матрица наблюдений
    y_oc = new double[inData.dimExp];//оцененный вектор отклика
    y_no_noise = new double[inData.dimExp];
rezMult_mv = new double[inData.m_loc];
    //величины для подсчета дисперсии
    double *s;//промежуточная величина
    s = new double[inData.dimExp];
    double yAverage = 0.0;// значение отклика среднее
    double w2 = 0.0;//мощность сигнала
    disperss = 0.0;
    e = 0.0;
    tempvect = new double[inData.m_loc];


    for (int i=0; i<inData.dimExp; i++)
        x_var[i] = new double[inData.dimFactor];

     for (int i=0; i<inData.m_loc; i++){
            rezMult_mv[i] = 0.0;
            tempvect[i] =0.0;

}
    for(int j=0;j<inData.dimFactor;j++)//генерация наблюдений
        for(int i=0;i<inData.dimExp;i++)
            x_var[i][j] = generationNumberRAV(inData.granic[0][0], inData.granic[0][1]);

    //вывод сгенерированных иксов
    ofstream out_X("X.txt");
    out_X << "X" << endl;
     for(int i = 0; i < inData.dimExp; i++)
         for(int j=0;j<inData.dimFactor;j++){
        {
         out_X << x_var[i][j] << "\t";

      }out_X << endl;
    }
     out_X.close();

    for(int i=0; i<inData.dimExp; i++)
        y_main[i] = currentFunction(i);//вычисление векторов отклика (моделирование данных)

    //вывод в файл незашумленного вектора отклика
    ofstream out_y_ist("y_ist.txt");
    out_y_ist << "y" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        out_y_ist << y_main[i];
        out_y_ist << endl;
    }
    out_y_ist.close();

    for(int i = 0; i < inData.dimExp; i++)
        y_no_noise[i] = y_main[i];

    for(int i=0;i<inData.dimExp;i++)
        yAverage += y_main[i];
    yAverage = yAverage/(double)inData.dimExp;//подсчет значения среднего отклика

    for(int i=0;i<inData.dimExp;i++)
        s[i] = y_main[i] - yAverage;//дополнительная переменная для подсчета мощности сигнала

    for(int i=0;i<inData.dimExp;i++)
        w2 += s[i] * s[i];

    w2 = w2 / (double)(inData.dimExp-1);//подсчет мощности сигнала

    disperss = (inData.level_noise*w2)/100;//подсчет дисперсии

    ofstream out_disp("disp.txt");
    out_disp << scientific;
    out_disp << "disperss" << endl;
    out_disp << disperss << endl;
    out_disp.close();

    for(int i=0;i<inData.dimExp;i++)
    {
        e = generationNumberNORMAL(0.0,disperss);//генерация ошибки
        y_main[i] += e;//получение зашумленного отклика
    }

    ofstream out_e("e.txt");
    out_e << scientific;
    out_e << "e" << endl;
    out_e << e << endl;
    out_e.close();

    //вывод в файл зашумленного вектора отклика
    ofstream out_y("y.txt");
    out_y << "y" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        out_y << y_main[i];
        out_y << endl;
    }
    out_y.close();

    delete [] s;
}

//инициализатор
void method::initialization_one_multi()
{
    x_var = new double*[inData.dimExp];
    y_main = new double[inData.dimExp];//двумерный массив отклика
    Xmat = new double*[inData.dimExp];//матрица наблюдений
    y_oc = new double[inData.dimExp];//оцененный вектор отклика
    y_no_noise = new double[inData.dimExp];
    y_matrix = new double*[inData.dimExp];
    tetta_matrix = new double*[inData.dimFactor+1];
    mse = 0.0;
    //величины для подсчета дисперсии
    double *s;//промежуточная величина
    s = new double[inData.dimExp];
    double yAverage = 0.0;// значение отклика среднее
    double w2 = 0.0;//мощность сигнала
    disperss = 0.0;
    e = 0.0;

    for (int i=0; i<inData.dimExp; i++)
        x_var[i] = new double[inData.dimFactor];

    for(int i=0; i<inData.dimFactor+1;i++)
        tetta_matrix[i] = new double[cluster.Nc];

    for(int i=0; i<inData.dimFactor+1;i++)
        for(int j=0; j<cluster.Nc;j++)
            tetta_matrix[i][j]=0.0;//строк по количеству факторов, столбцы - по количеству кластеров

    for(int j=0;j<inData.dimFactor;j++)//генерация наблюдений
        for(int i=0;i<inData.dimExp;i++)
            x_var[i][j] = generationNumberRAV(inData.granic[0][0], inData.granic[0][1]);

        ofstream out_Xx("X.txt");
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j < inData.dimFactor; j++)
            out_Xx << x_var[i][j] << "\t";
        out_Xx << endl;
    }
    out_Xx << "\n";
    out_Xx.close();

    //вывод сгенерированных иксов
    ofstream out_X("X1.txt");
    out_X << "X" << endl;
    for(int i=0;i<inData.dimExp;i++)
            out_X << x_var[i][0] << endl;
    out_X.close();

        //вывод сгенерированных иксов
    ofstream out_X2("X2.txt");
    out_X2 << "X" << endl;
    for(int i=0;i<inData.dimExp;i++)
            out_X2 << x_var[i][1] << endl;
    out_X.close();

    for(int j=0;j<inData.dimFactor;j++)
        for(int i=0; i<inData.dimExp; i++)
            y_main[i] = currentFunction(i);//вычисление векторов отклика (моделирование данных)

    for(int i=0;i<inData.dimExp;i++)
        y_no_noise[i] = y_main[i];

    for(int i=0;i<inData.dimExp;i++)
        yAverage += y_main[i];
    yAverage = yAverage/inData.dimExp;//подсчет значения среднего отклика

    for(int i=0;i<inData.dimExp;i++)
        s[i] = y_main[i] - yAverage;//дополнительная переменная для подсчета мощности сигнала

    for(int i=0;i<inData.dimExp;i++)
        w2 += s[i] * s[i];

    w2 = w2 / (inData.dimExp-1);//подсчет мощности сигнала

    disperss = (inData.level_noise*w2)/100;//подсчет дисперсии

    for(int i=0;i<inData.dimExp;i++)
    {
        e = generationNumberNORMAL(0.0,disperss);//генерация ошибки
        y_main[i] += e;//получение зашумленного отклика
        y_oc[i] = 0.0;
        y_matrix[i]=new double[cluster.Nc];
    }
    for(int i=0;i<inData.dimExp;i++)
        for(int j=0;j<cluster.Nc;j++)
            y_matrix[i][j]=0.0;//строк по количеству наблюдений, столбцы - по количеству кластеров

    //вывод в файл зашумленного вектора отклика
    ofstream out_y2("y.txt");
    for(int i = 0; i < inData.dimExp; i++)
    {
        out_y2 << y_main[i];
        out_y2 << endl;
    }
    out_y2.close();

    delete [] s;
}

//инициализатор для двумерного случая
void method::initialization_two()
{
    x_two = new double*[inData.dimExp];//двумерный массив иксов(строк)
    y_main = new double[inData.dimExp];//двумерный массив отклика
    Xmat = new double*[inData.dimExp];//матрица наблюдений
    y_oc = new double[inData.dimExp];//оцененный вектор отклика

    //величины для подсчета дисперсии
    double *s;//дополнительная величина
    s = new double[inData.dimExp];
    double yAverage = 0.0;// значение отклика среднее
    double w2 = 0.0;//мощность сигнала
    disperss = 0.0;
    e = 0.0;

    for(int i=0;i<inData.dimExp;i++)
       {
        x_two[i]=new double[inData.dimFactor];
       }

    for(int i=0;i<inData.dimExp;i++){//генерация наблюдений
        x_two[i][0]=generationNumberRAV(inData.granic[0][0],inData.granic[0][1]);
        x_two[i][1]=generationNumberRAV(inData.granic[1][0],inData.granic[1][1]);}


    //вывод сгенерированных иксов
    ofstream out_X("X.txt");
    out_X << "X" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j < inData.dimFactor; j++)
            out_X << x_two[i][j]<< "\t";
        out_X << endl;
    }
    out_X.close();

    //вывод сгенерированных иксов x0 (для построения графика выводим отдельно факторы)
    ofstream out_X0("X0.txt");
    out_X0 << "X0" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {out_X0 << x_two[i][0];
        out_X0 << endl;}
    out_X0.close();

    //вывод сгенерированных иксов x1 (для построения графика выводим отдельно факторы)
    ofstream out_X1("X1.txt");
    out_X1 << "X1" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {out_X1 << x_two[i][1];
        out_X1 << endl;}
    out_X1.close();

    for(int i=0; i<inData.dimExp; i++)
        y_main[i] = currentFunction(i);// вычисление вектора отклика

    for(int i=0;i<inData.dimExp;i++)
        yAverage += y_main[i];
    yAverage = yAverage/inData.dimExp;//подсчет значения среднего отклика

    for(int i=0;i<inData.dimExp;i++)
        s[i] = y_main[i]-yAverage;//дополнительная переменная для подсчета мощности сигнала

    for(int i=0;i<inData.dimExp;i++)
        w2 += s[i]*s[i];

    w2 = w2/(inData.dimExp-1);//подсчет мощности сигнала

    disperss = (inData.level_noise*w2)/100;

    ofstream out_disp("disp.txt");
    out_disp << scientific;
    out_disp << "disperss" << endl;
    out_disp << disperss << endl;
    out_disp.close();

    for(int i=0;i<inData.dimExp;i++)
    {
        e = generationNumberNORMAL(0.0,disperss);//генерация ошибки
        y_main[i] += e;//получение зашумленного отклика
    }

    ofstream out_e("e.txt");
    out_e << scientific;
    out_e << "e" << endl;
    out_e << e << endl;
    out_e.close();

    //вывод в файл истинного вектора отклика
    ofstream out_y("y.txt");
    out_y << "y" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        out_y << y_main[i];
        out_y << endl;
    }
    out_y.close();

    delete [] s;
}

//определение количество функций принадлежности
int method::number_FP(int n_x, int n_y)
{
    if (inData.dimFactor == 1)//если один фактор
    {
        if (inData.choiceFunction == 1) number_mu = n_x;//количество функций принадлежности если треугольники
        if (inData.choiceFunction == 2) number_mu = sector_n/2 + 1;//если трапеции
    }
    else//если два фактора
    {
        if (inData.choiceFunction == 1) number_mu = n_x * n_y;//количество функций принадлежности если треугольники
        if (inData.choiceFunction == 2) number_mu = (n_x - 2) * (n_y - 2);//если трапеции
    }
    return number_mu;
}

//построение сетки для одного фактора (отрезки)
void method::buildGridFactorOne()
{
    double *setka[2];
    n_x++;//количество точек на 1 больше , чем количество отрезков

    setka[0] = new double [n_x];

    for(int i = 0; i < n_x; i++)
        input_grid1 >> setka[0][i];//отрезки по оси х

    input_grid1.close();

    sector_n = n_x - 1;//количество отрезков

    number_FP(n_x, 0);//определение количества ФП

    D = new sector [sector_n];

    for(int sector_i = 0; sector_i < sector_n; sector_i++)//по каждому отрезку
    {
        //определение вершин отрезка
        D[sector_i].a = setka[0][sector_i];//sector_i-номер отрезка
        D[sector_i].b = setka[0][sector_i+1];


        //вывод в файл незашумленного вектора отклика
        ofstream ft("ft.txt");
        ft << "y" << endl;
        ft << D[sector_i].a << endl;
        ft << D[sector_i].b << endl;
        ft.close();


        D[sector_i].number_a = sector_i;
        D[sector_i].number_b = sector_i+1;

        ofstream ft2("ft2.txt");
        ft2 << "y" << endl;
        ft2 << D[sector_i].number_a << endl;
        ft2 << D[sector_i].number_b << endl;
        ft2.close();
    }

    loc_number_mu = number_mu;//количество номеров ФП
    mu_numbers_x = new int *[sector_n];

    for(int i = 0; i < sector_n; i++)
        mu_numbers_x[i] = new int [loc_number_mu];

    for(int i = 0; i < inData.dimExp; i++)//по всем экспериментам
    {
        bool find = false;
        for(int j = 0; j < sector_n && !find; j++)//по всем отрезкам
        {
            if(D[j].in_sector(x_var[i][0]))//если точка входит в отрезок
            {
                D[j].xx_one.push_back(x_var[i][0]);//сформировали правильную сетку
                D[j].number_x_one.push_back(i);//и сформировали правильную нумерацию узлов

                if (inData.choiceFunction==1)//если треугольники
                {
                    mu_numbers_x[j][0] = 0; mu_numbers_x[j][1] = 1;
                }
                else//если трапеции
                {
                    mu_numbers_x[j][0] = j/2;//определяем номер ФП на j-ом отрезке
                    mu_numbers_x[j][1] = 0;
                    if (j%2==1)
                        mu_numbers_x[j][1] = mu_numbers_x[j][0] + 1;//там где две ФП на отрезке
                }
                find = true;
            }
        }
    }

    if (inData.numberRules == 1) //одно правило
    {
        if (inData.choiceFunction == 1)//если треугольники
        {
            for(int i=0;i<inData.dimExp;i++)
            {
                if (inData.flag_about_free == 0)
                    Xmat[i] = new double[number_mu + 1];//под свободный член оставляем  только один столбец
                else Xmat[i] = new double[number_mu * 2];}
        }
        if (inData.choiceFunction == 2)//если трапеции
        {
            for(int i=0;i<inData.dimExp;i++)
                Xmat[i] = new double[number_mu * 2];//для трапеций для каждой мюшки будет свободный член
        }
    }
    else
        if (inData.numberRules == 2)//два правила
        {
            if (inData.choiceFunction == 1)//если треугольники
            {
                {for(int i=0;i<inData.dimExp;i++)
                    { if (inData.flag_about_free == 0) Xmat[i] = new double[number_mu + 1];//под свободный член оставляем  только один столбец
                        else Xmat[i] = new double[number_mu * 2];}}
            }
            if (inData.choiceFunction == 2)//если трапеции
            {
                for(int i=0;i<inData.dimExp;i++)
                    Xmat[i] = new double[number_mu * 2];//для трапеций для каждой мюшки будет свободный член
            }
        }
        else//три правила
        {
            if (inData.choiceFunction == 1)//если треугольники
            {
                {   for(int i=0;i<inData.dimExp;i++)
                    {if (inData.flag_about_free == 0) Xmat[i] = new double[number_mu + 1];//под свободный член оставляем  только один столбец
                        else Xmat[i] = new double[number_mu * 2];}}
            }
            if (inData.choiceFunction == 2)//если трапеции
            {
                for(int i=0;i<inData.dimExp;i++)
                    Xmat[i] = new double[number_mu * 2];//для трапеций для каждой мюшки будет свободный член
            }
        }
    delete [] setka[0];
}

//построение сетки для двух факторов (прямоугольники)
void method::buildGridFactorTwo()
{
    double *setka[2];//двумерная сетка

    ifstream input_grid3;
    if (inData.choiceFunction == 1) input_grid3.open("setkaFactorTriTwo11.txt");//данные для треугольников

    input_grid3 >> n_x >> n_y;
    n_x++;//количество точек на 1 больше , чем количество отрезков
    n_y++;

    setka[0] = new double [n_x];
    setka[1] = new double [n_y];

    for(int i = 0; i < n_x; i++)
        input_grid3 >> setka[0][i];//отрезки по оси х

    for(int i = 0; i < n_y; i++)
        input_grid3 >> setka[1][i];//отрезки по оси у

    input_grid3.close();

    if (inData.choiceFunction == 2) rect_n = (n_x - 1) * (n_y - 1);//общее количество прямоугольников если трапеции
    else rect_n = (n_x - 1) * (n_y - 1);
    number_FP(n_x, n_y);//определение количества ФП

    C = new rectangle [rect_n];

    for(int rect_i = 0; rect_i < rect_n; rect_i++)
    {
        int rect_layers_x = rect_i / (n_x - 1);//количество пройденных слоев по x
        int a_x_i = rect_i - rect_layers_x * (n_x - 1);//координата прямоугольника по х
        int a_y_i = rect_layers_x;//координата прямоугольника по у

        //определние вершин прямоугольника
        C[rect_i].a[0] = setka[0][a_x_i];
        C[rect_i].b[0] = setka[0][a_x_i+1];
        C[rect_i].a[1] = setka[1][a_y_i];
        C[rect_i].b[1] = setka[1][a_y_i+1];

        //определение номеров вершин прямоугольника
        C[rect_i].number_a[0] = a_x_i;
        C[rect_i].number_b[0] = a_x_i+1;
        C[rect_i].number_a[1] = a_y_i;
        C[rect_i].number_b[1] = a_y_i+1;

        C[rect_i].n_x = n_x;
        C[rect_i].n_y = n_y;
    }

    loc_number_mu = number_mu;//количество номеров ФП
    mu_numbers_x = new int *[rect_n];
    mu_numbers_y = new int *[rect_n];

    for(int i = 0; i < rect_n; i++) {
        mu_numbers_x[i] = new int [loc_number_mu];
        mu_numbers_y[i] = new int [loc_number_mu]; }


    for(int i = 0; i < inData.dimExp; i++)//по всем экспериментам
    {
        bool find = false;
        for(int j = 0; j < rect_n && !find; j++)//по всем прямоугольникам
        {
            if(C[j].in_rect(x_two[i]))
            {
                C[j].xx_two.push_back(x_two[i]);//сформировали правильную сетку
                C[j].number_x_two.push_back(i);//и сформировали правильную нумерацию узлов
                if (inData.choiceFunction==1)//если треугольники
                {
                    mu_numbers_x[j][0] = 0; mu_numbers_x[j][1] = 1; mu_numbers_y[j][0] = 0; mu_numbers_y[j][1] = 1;
                }
                else//если трапеции
                {
                    mu_numbers_x[j][0] = j/2;//определяем номер ФП на j-ом отрезке
                    mu_numbers_x[j][1] = 0;
                    mu_numbers_y[j][0] = j/2;
                    mu_numbers_y[j][1] = 0;
                    if (j%2==1) {mu_numbers_x[j][1] = mu_numbers_x[j][0] + 1; mu_numbers_y[j][1] = mu_numbers_y[j][0] + 1;}//там где две мюшки на отрезке
                }
                find = true;
            }
        }
    }

    if (inData.numberRules == 1) //одно правило
    {
        if (inData.choiceFunction == 1)//если треугольники
        {
            for(int i=0;i<inData.dimExp;i++)
            {
                if (inData.flag_about_free == 1) Xmat[i] = new double[number_mu * 3];
                else Xmat[i] = new double[number_mu * 2 + 1];}//под свободный член оставляем  только один столбец
        }
        if (inData.choiceFunction == 2)//если трапеции
        {
            for(int i=0;i<inData.dimExp;i++)
                Xmat[i] = new double[number_mu * 3];//для трапеций для каждой ФП будет свободный член
        }
    }
    else
        if (inData.numberRules == 2)//два правила
        {
            if (inData.choiceFunction == 1)//если треугольники
            {
                for(int i=0;i<inData.dimExp;i++)
                {	if (inData.flag_about_free == 1) Xmat[i] = new double[number_mu * 3];
                    else Xmat[i] = new double[number_mu *2 + 1];}//под свободный член оставляем  только один столбец
            }
            if (inData.choiceFunction == 2)//если трапеции
            {
                for(int i=0;i<inData.dimExp;i++)
                    Xmat[i] = new double[number_mu * 3];//для трапеций для каждой ФП будет свободный член
            }
        }
        else//три правила
        {
            if (inData.choiceFunction == 1)//если треугольники
            {
                for(int i=0;i<inData.dimExp;i++)
                {	if (inData.flag_about_free == 1) Xmat[i] = new double[number_mu * 3];
                    else Xmat[i] = new double[number_mu * 2 + 1];}//под свободный член оставляем  только один столбец
            }
            if (inData.choiceFunction == 2)//если трапеции
            {
                for(int i=0;i<inData.dimExp;i++)
                    Xmat[i] = new double[number_mu * 3];//для трапеций для каждой ФП будет свободный член
            }
        }
    delete [] setka[0];
    delete [] setka[1];
}

//функция построения матрицы наблюдений для одного фактора для ТРЕУГОЛЬНИКОВ
void method::constructMatrixX_one_tri()
{
    if (inData.numberRules == 1)//если одно правило
    {
        if (inData.flag_about_free == 1)
            inData.m_loc = number_mu * 2;//если со всеми свободными членами
        else
            inData.m_loc = number_mu + 1; }//если свободный член один = 1
    else
    {
        if (inData.numberRules == 2)//если 2 правила
        {
            if (inData.flag_about_free == 1) inData.m_loc = number_mu * 2;
            else inData.m_loc = number_mu + 1; }
        else//если 3 правила
        {
            if (inData.flag_about_free == 1) inData.m_loc = number_mu * 2;
            else inData.m_loc = number_mu + 1; }
    }

    for( int i=0; i<inData.dimExp; i++)//для каждого эксперимента
    {
        for(int j = 0 ; j < inData.m_loc; j++)
            Xmat[i][j] = 0;//обнуляем элементы
    }
    if (inData.flag_about_free == 0)//если свободный член один = 1
    {
        for( int i=0; i<inData.dimExp; i++)//для каждого эксперимента
            Xmat[i][0] = 1;//выделяем первый столбец под свободный член полностью из единиц
    }

    int col_start;
    for(int sector_i = 0 ; sector_i < sector_n; sector_i++)//по каждому отрезку
    {
        for(int point_i = 0; point_i < D[sector_i].xx_one.size(); point_i++)//по всем точкам в отрезке
        {
            for(int mu_i = 0; mu_i < 2; mu_i++)//по всем функиям принадлежности
            {
                if (inData.flag_about_free == 1)//если со всеми свободными членами
                    col_start = 2 * D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x);//столбец
                else col_start = D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x) + 1;//столбец
                int row = D[sector_i].number_x_one[point_i];//строка
                double mu_v = D[sector_i].mu_val_tri_one(mu_i, D[sector_i].xx_one[point_i]);//значение функции принадлежности в иксе

                if (inData.flag_about_free == 1)//если со всеми свободными членами
                {
                    Xmat[row][col_start] = mu_v;
                    Xmat[row][col_start+1] = mu_v * D[sector_i].xx_one[point_i];//получение значения элемента в матрице наблюдений
                }
                else Xmat[row][col_start] = mu_v * D[sector_i].xx_one[point_i];//получение значения элемента в матрице наблюдений
            }
        }
    }
    ofstream out_mat("Xmat.txt");
    out_mat << "Xmat" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j < inData.m_loc; j++)
            out_mat << Xmat[i][j] << "  \t";
        out_mat << endl;
    }
    out_mat << "\n";
    out_mat.close();
}


void method::constructMatrix_cluster()
{
    cluster.dim = inData.dimFactor;

    for(int i=0;i<inData.dimExp;i++)
        Xmat[i] = new double[cluster.dim+1];

    for( int i=0; i<inData.dimExp; i++)
        for(int j = 0 ; j < cluster.dim+1; j++)
            Xmat[i][j] = 0;

    for( int i=0; i<inData.dimExp; i++)
        Xmat[i][0] = 1;//выделяем первый столбец под свободный член полностью из единиц

    for( int j=0; j<cluster.dim; j++)
        for( int i=0; i<inData.dimExp; i++)
            Xmat[i][j+1] = x_var[i][j];

    ofstream out_mat("Xmat.txt");
    out_mat << "Xmat" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j <cluster.dim+1; j++)
            out_mat << Xmat[i][j] << "  \t";
        out_mat << endl;
    }
    out_mat << "\n";
    out_mat.close();
}

//функция построения матрицы наблюдений для двух факторов для ТРЕУГОЛЬНИКОВ
void method::constructMatrixX_two_tri()
{
    if (inData.flag_about_free == 1) inData.m_loc = number_mu * 3;//если со всеми свободными членами
    else inData.m_loc = number_mu * 2 + 1;//если свободный член один = 1

    for( int i=0; i<inData.dimExp; i++)//для каждого эксперимента
    {
        for(int j = 0 ; j < inData.m_loc; j++)
            Xmat[i][j] = 0;//обнуляем элементы
    }
    if (inData.flag_about_free == 0)//если свободный член один = 1
    {	for( int i=0; i<inData.dimExp; i++)//для каждого эксперимента
            Xmat[i][0] = 1;//выделяем первый столбец под свободный член полностью из единиц
    }
    int col_start1,col_start2;
    for(int rect_i = 0 ; rect_i < rect_n; rect_i++)//по каждому прямоугольнику
    {
        for(int point_i = 0; point_i < C[rect_i].xx_two.size(); point_i++)//по всем точкам в прямоугольнике
        {
            for(int mu_i = 0; mu_i < 4; mu_i++)//по всем функиям принадлежности
            {
                if (inData.flag_about_free == 0)//если свободный член один = 1
                {
                    col_start1 = 2 * C[rect_i].mu_number_two(mu_i, rect_i, inData.choiceFunction, mu_numbers_x, mu_numbers_y) + 1;
                    col_start2 = 2 * C[rect_i].mu_number_two(mu_i, rect_i, inData.choiceFunction, mu_numbers_x, mu_numbers_y) + 2;
                }
                else col_start1 = 3 * C[rect_i].mu_number_two(mu_i, rect_i, inData.choiceFunction, mu_numbers_x, mu_numbers_y);
                int row = C[rect_i].number_x_two[point_i];
                double mu_v = C[rect_i].mu_val_tri_two(mu_i, C[rect_i].xx_two[point_i]);//значение ФП

                if (inData.flag_about_free == 0)//если свободный член один = 1
                {
                    Xmat[row][col_start1] = mu_v * C[rect_i].xx_two[point_i][0];
                    Xmat[row][col_start2] = mu_v * C[rect_i].xx_two[point_i][1];
                }
                else
                {
                    Xmat[row][col_start1] = mu_v ;
                    Xmat[row][col_start1+1] = mu_v * C[rect_i].xx_two[point_i][0];
                    Xmat[row][col_start1+2] = mu_v * C[rect_i].xx_two[point_i][1];
                }
            }
        }
    }
    ofstream out_mat("Xmat.txt");
    out_mat << "Xmat" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j < inData.m_loc; j++)
            out_mat << Xmat[i][j] << "  \t";
        out_mat << endl;
    }
    out_mat << "\n";
    out_mat.close();
}

//функция построения матрицы наблюдений для одного фактора для ТРАПЕЦИЙ
void method::constructMatrixX_one_tra()
{
    if (inData.numberRules == 1) inData.m_loc = number_mu * 2;//если одно правило
    else
    {
        if (inData.numberRules == 2) inData.m_loc = number_mu * 2;//если 2 правила
        else inData.m_loc = number_mu * 2;//если 3 правила
    }

    for( int i=0; i<inData.dimExp; i++)//для каждого эксперимента
    {
        for(int j = 0 ; j < inData.m_loc; j++)
            Xmat[i][j] = 0;//обнуляем элементы
    }

    int flag = 0;
    for(int sector_i = 0 ; sector_i < sector_n; sector_i++)//по каждому отрезку
    {
        if (flag == 0)//если не построили прямую, идем ее строить
        {
            int mu_i = 0;//участок, где рассматривается прямая у трапеции mu_i = 0 - mu_val_tra_one(0) = 1.0
            for(int point_i = 0; point_i < D[sector_i].xx_one.size(); point_i++)//по всем точкам в отрезке
            {
                int col_start = 2 * D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x);//индекс столбца
                int row = D[sector_i].number_x_one[point_i];//индекс строки
                double mu_v = D[sector_i].mu_val_tra_one(mu_i, D[sector_i].xx_one[point_i]);//значение функции принадлежности в иксе
                Xmat[row][col_start] = mu_v;
                Xmat[row][col_start+1] = mu_v * D[sector_i].xx_one[point_i];//полчучение собсно значения элемента в матрице наблюдений

            }
            flag = 1;//прямую прошли, теперь надо перейти к треугольникам
        }
        else//если построили  прямую, идем строить треугольники
        {
            for (int mu_i = 1; mu_i < 3; mu_i++)//участок, где рассматривается правая часть треугольника
            {
                for(int point_i = 0; point_i < D[sector_i].xx_one.size(); point_i++)//по всем точкам в отрезке
                {
                    int col_start = 2*D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x);//столбец
                    int row = D[sector_i].number_x_one[point_i];//строка
                    double mu_v = D[sector_i].mu_val_tra_one(mu_i, D[sector_i].xx_one[point_i]);//значение функции принадлежности в иксе

                    Xmat[row][col_start] = mu_v;
                    Xmat[row][col_start+1] = mu_v * D[sector_i].xx_one[point_i];
                }
                flag = 0;
            }
        }
    }

    ofstream out_mat("Xmat.txt");
    out_mat << "Xmat" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j < inData.m_loc; j++)
            out_mat << Xmat[i][j] << "  \t";
        out_mat << endl;
    }
    out_mat << "\n";
    out_mat.close();
}

//выбор функции для исследований
double method::currentFunction(int i)//выбор функции (отклика) для исследований
{
    switch (inData.dimFactor)//сколько факторов
    {
    case 1: {
        switch (inData.numberRules)//сколько правил
                {
                case 1:	if(x_var[i][0]<1) return exp(x_var[i][0] * x_var[i][0]) + x_var[i][0] * x_var[i][0];
                case 2:
                    if(x_var[i][0]<=0) return 2 + x_var[i][0] * x_var[i][0];//return x_var[i][0] * x_var[i][0] + 0.2 * x_var[i][0];
                    if(x_var[i][0]<1) return 5*x_var[i][0] *x_var[i][0];//return -x_var[i][0] * x_var[i][0] * x_var[i][0];
                case 3:
                    if(x_var[i][0]<=-0.5) return x_var[i][0] * x_var[i][0];
                    if(x_var[i][0]<=0.5) return 0.8 * x_var[i][0] * x_var[i][0];
                    if(x_var[i][0]<1) return x_var[i][0] * x_var[i][0];
                }
            };

    }
}

//транпонирование матрицы
double **method::TranspositionMatrix(double **xx, double **xTT)
{
    for (int i = 0; i < inData.dimExp; i++)
        for (int j = 0; j < number_mu+1; j++)
            xTT[j][i] = xx[i][j];//меняем элементы местами
    return xTT;
}

//обращение матрицы
double **method::InversionMatrix()
{
    double **I;
    double **Xrez;
    I = new double*[inData.m_loc];//единичная матрица
    Xrez = new double*[inData.m_loc];

    for(int i=0; i<inData.m_loc; i++)
    {
        I[i]=new double[inData.m_loc];
        Xrez[i]=new double[inData.m_loc];
    }

    for(int i = 0 ; i < inData.m_loc; i++)
        for(int j = 0 ; j < inData.m_loc; j++)
        {
            if (i==j) I[i][j] = 1.0;
            else I[i][j] = 0.0;
        }

    //для обращения матрицы используем метод Гаусса Жордана, решаем СЛАУ АХ=I
    SLAU_solution_Gauss( mult_xt_w, I, Xrez, inData.m_loc );

    ofstream out_mat("XmatInv.txt");
    out_mat << "XmatInv" << endl;
    for(int i = 0; i < inData.m_loc; i++)
    {
        for(int j = 0; j < inData.m_loc; j++)
            out_mat << Xrez[i][j] << "  \t";
        out_mat << endl;
    }
    out_mat << "\n";
    out_mat.close();

    return Xrez;
}

//решение слау А*Хtr=I
bool method::SLAU_solution_Gauss(double **A, double **I, double **Xr, int m)
{
    for(int i = 0 ; i < m; i++)
        for(int j = 0 ; j < m; j++)
            Xr[i][j] = I[i][j];//предполагаем, что обратная матрица единичная

    int flag = trianglematrix1(A,Xr,m);//приведем матрицу А к треугольному виду

    if(flag==0) return false;

    double sum=0;

    for (int i = 0; i < m ; i++)
    {
        sum = A[i][i];
        A[i][i] = A[i][i]/sum;

        for(int k = 0; k < m; k++)
            Xr[i][k] = Xr[i][k]/sum;
    }
    return true;
}
//Приведение матрицы к верхнему треугольному виду
bool method::trianglematrix1(double **Atr, double **Xtr, int m)
{
    int flag=1;

    for(int i = 0 ; i < m ; i++)
    {
        double A_d = Atr[i][i];//ведущий элемент

        transf1(Atr,Xtr,i,m,A_d);//переставим строки местами

        if(fabs(A_d) < 1E-20) return flag=0;

        for(int j = 0; j < m; j++)
        {
            if (i != j)
            {
                double A_j = Atr[j][i] / Atr[i][i];

                for(int k = 0; k < m; k++)
                {
                    Atr[j][k] = Atr[j][k] - Atr[i][k]*A_j;
                    Xtr[j][k] = Xtr[j][k] - Xtr[i][k]*A_j;
                }
            }
        }
    }
    return flag;
}
// перестановка строк
void method::transf1(double **Aa, double **Xx, int i, int m, double &A_d)
{
    int line1 = i;

    for(int j = i; j < m; j++)
        if(fabs(Aa[j][i]) > fabs(A_d))
        {
            line1 = j;
            A_d=Aa[j][i];
        }

    double c;
    for(int j = 0; j < m; j++)
    {
        //меняем местами строки в матрице А
        c = Aa[i][j];
        Aa[i][j] = Aa[line1][j];
        Aa[line1][j] = c;
        //меняем местами строки в матрице Х
        c = Xx[i][j];
        Xx[i][j] = Xx[line1][j];
        Xx[line1][j] = c;
    }
}

//функция перемножения матриц:
//случай перемножения транспонированной на прямую матрицу
double **method::MultMM1(double **x1, double **x2, int n, int m, int l)
{
    for( int i=0; i<n; i++ )//n-цикл по строкам х1
        for( int j=0; j<l; j++ )//l-столбцы х2
        {
            rezMult1[i][j]=0;
            for ( int k=0; k<m; k++ )//m-строки х2 столбцы х1
                rezMult1[i][j]+=x1[i][k]*x2[k][j];
        }
    return rezMult1;
}


double **method::MultMM3(double **x1, double **x2, int n, int m, int l)
{
    for( int i=0; i<n; i++ )//n-цикл по строкам х1
        for( int j=0; j<l; j++ )//l-столбцы х2
        {
            rezMult2[i][j]=0;
            for ( int k=0; k<m; k++ )//m-строки х2 столбцы х1
                rezMult2[i][j]+=x1[i][k]*x2[k][j];
        }
    return rezMult2;
}


//функция перемножения матриц:
//случай перемножения обратной на транспонированную
double **method::MultMM2(double **x1, double **x2, int n, int m)
{
    for( int i=0; i<m; i++ )//m-цикл по строкам х1
        for( int j=0; j<n; j++ )//n-столбцы х2
        {
            rezMult3[i][j]=0;
            for ( int k=0; k<m; k++ )//m-строки х2 столбцы х1
                rezMult3[i][j]+=x1[i][k]*x2[k][j];
        }
    return rezMult3;
}

double *method::MultMV(int m_loc, double *rezMult_mv)
{
    rezMult_mv = new double [inData.m_loc];

    for( int i=0; i<m_loc; i++ )//цикл по строкам х
    {
        rezMult_mv[i]=0;
        for ( int j=0; j<inData.dimExp; j++ )
        {rezMult_mv[i]+=mult_xt_w_x[i][j]*y_main[j];
            if(fabs(rezMult_mv[i]) < 1E-17) rezMult_mv[i]=0;}
    }
    return rezMult_mv;
}

//функция умножения матрицы на вектор
double *method::MultMV_cluster()
{
    for( int i=0; i<inData.dimFactor+1; i++ )//цикл по строкам х
    {
        rezMult_onY[i]=0;
        for ( int j=0; j<inData.dimExp; j++ )
            rezMult_onY[i]+=mult_all_on_W[i][j]*y_main[j];
    }

    ofstream out_rezMult_onY("rezMult_onY.txt");
    for(int i = 0; i < inData.dimFactor+1; i++)
    {
        out_rezMult_onY << rezMult_onY[i];
        out_rezMult_onY << endl;
    }
    out_rezMult_onY.close();

    return rezMult_onY;
}

//функция получения оцениваемых параметров вектора отклика
void method::Tetta()
{
    tetta = new double[inData.m_loc];//вектор параметров
    X_t = new double*[inData.m_loc];//транспонированная матрица
    mult_xt_w = new double*[inData.m_loc];//произведение транспонированной на прямую матрицу
    Invers = new double*[inData.m_loc];//обратная матрица
    mult_xt_w_x = new double*[inData.m_loc];//произведение обратной матрицы на транпонированную



    for(int i=0; i<inData.m_loc; i++)
    {
        X_t[i]=new double[inData.dimExp];
        mult_xt_w[i]=new double[inData.m_loc];
        Invers[i]=new double[inData.m_loc];
        mult_xt_w_x[i]=new double[inData.dimExp];
    }
    x_for_graphic = new double*[inData.dimExp];
    for(int i=0; i<inData.dimExp; i++)
        x_for_graphic[i] = new double[2];

    //на всякий случай обнуляем все величины для МНК
    for(int i=0; i<inData.m_loc; i++)
    {
        for(int j=0; j<inData.dimExp; j++)
        {
            X_t[i][j]=0.0;
            mult_xt_w_x[i][j]=0.0;
        }
    }

    for(int i=0; i<inData.m_loc; i++)
    {
        for(int j=0; j<inData.m_loc; j++)
        {
            mult_xt_w[i][j]=0.0;
            Invers[i][j]=0.0;

        }
    }

        double **xT;
    xT = new double*[inData.m_loc];

    for( int i=0; i<inData.m_loc; i++ )
        xT[i]=new double[inData.dimExp];

    for( int i=0; i<inData.m_loc; i++ )
        for( int j=0; j<inData.dimExp; j++ )
            xT[i][j] = 0.0;

    //вычисление транспонированной матрицы
    X_t = TranspositionMatrix(Xmat, xT);

    ofstream out_X_t("X_t.txt");
    out_X_t << "X_t" << endl;
    for(int i = 0; i < inData.m_loc; i++)
    {
        for(int j = 0; j < inData.dimExp; j++)
            out_X_t << X_t[i][j] << "  \t";
        out_X_t << endl;
    }
    out_X_t << "\n";
    out_X_t.close();


    rezMult1 = new double*[inData.m_loc];
    for (int i=0; i<inData.m_loc; i++ )
        rezMult1[i] = new double[inData.dimExp];

    for (int i=0; i<inData.m_loc; i++ )
        for (int j=0; j<inData.dimExp; j++ )
            rezMult1[i][j]=0.0;

    // произведение транспонированной на прямую
    mult_xt_w = MultMM1 ( X_t, Xmat, inData.m_loc, inData.dimExp, inData.m_loc );

    ofstream out_mult_xt_x("mult_xt_w.txt");
    out_mult_xt_x << "mult_xt_w" << endl;
    for(int i = 0; i < inData.m_loc; i++)
    {
        for(int j = 0; j < inData.m_loc; j++)
            out_mult_xt_x << mult_xt_w[i][j] << "  \t";
        out_mult_xt_x << endl;
    }
    out_mult_xt_x << "\n";
    out_mult_xt_x.close();


    //обращение матрицы
    Invers = PseudoInverse(mult_xt_w, inData.m_loc);

    rezMult3 = new double*[inData.m_loc];
    for (int i=0; i<inData.m_loc; i++ )
        rezMult3[i] = new double[inData.dimExp];

    for (int i=0; i<inData.m_loc; i++ )
        for (int j=0; j<inData.dimExp; j++ )
            rezMult3[i][j]=0.0;

    //произведение обратной на траспонированную
    mult_xt_w_x = MultMM2 (Invers,X_t, inData.dimExp, inData.m_loc);

    ofstream out_mult_obr_xt("mult_xt_w_x.txt");
    out_mult_obr_xt << "mult_xt_w_x" << endl;
    for(int i = 0; i < inData.m_loc; i++)
    {
        for(int j = 0; j < inData.dimExp; j++)
            out_mult_obr_xt << mult_xt_w_x[i][j] << "  \t";
        out_mult_obr_xt << endl;
    }
    out_mult_obr_xt << "\n";
    out_mult_obr_xt.close();

    // произведение матрицы на вектор у, (Х^t * X )^-1 * Х^t * y = Tetta
     tetta = MultMV ( inData.m_loc , rezMult_mv);

    ofstream out_tet("tetta.txt");
    out_tet << scientific;
    out_tet << "tetta" << endl;
    for(int i = 0; i < inData.m_loc; i++)
    {
        out_tet << tetta[i] << "  \t";
        out_tet << endl;
    }
    out_tet.close();


}


double method::Tetta_cluster(int k)
{
    tetta = new double[inData.dimFactor+1];//вектор параметров
    W_mu = new double*[inData.dimExp];//матрица принадлежности
    X_t = new double*[inData.dimFactor+1];//транспонированная матрица
    mult_xt_w = new double*[inData.dimFactor+1];//произведение транспонированной на прямую матрицу
    mult_xt_w_x = new double*[inData.dimFactor+1];
    Invers = new double*[inData.dimFactor+1];//обратная матрица
    mult_invers_xt = new double*[inData.dimFactor+1];
    mult_all_on_W = new double*[inData.dimFactor+1];
    rezMult_onY = new double[inData.dimFactor+1];//результат произведения матрицы на вектор

    for(int i=0; i<inData.dimExp; i++)
        W_mu[i] = new double[inData.dimExp];

    for( int i=0; i<inData.dimExp; i++)
        for( int j=0; j<inData.dimExp; j++)
            W_mu[i][j] = 0.0;

    for( int i=0; i<inData.dimExp; i++)
        for( int j=0; j<inData.dimExp; j++){
            if (i!=j)
                W_mu[i][j] = 0.0;
            else
                W_mu[i][j] = cluster.mu_prev[i][k];}

    ofstream WW("W_mu.txt");
    WW << "W_mu" << endl;
    for(int i = 0; i < inData.dimExp; i++)
    {
        for(int j = 0; j < inData.dimExp; j++)
            WW << W_mu[i][j] << "  \t";
        WW << endl;
    }
    WW << "\n";
    WW.close();

    for(int i=0; i<inData.dimFactor+1; i++)
    {
        X_t[i]=new double[inData.dimExp];
        mult_xt_w[i]=new double[inData.dimExp];
        Invers[i]=new double[inData.dimFactor+1];
        mult_xt_w_x[i]=new double[inData.dimFactor+1];
        mult_invers_xt[i] = new double[inData.dimExp];
        mult_all_on_W[i] = new double[inData.dimExp];
        rezMult_onY[i] = 0.0;
    }

    //на всякий случай обнуляем все величины для МНК
    for(int i=0; i<inData.dimFactor+1; i++){
        for(int j=0; j<inData.dimExp; j++){
            X_t[i][j]=0.0;
            mult_xt_w[i][j]=0.0;
            mult_all_on_W[i][j]=0.0;
            mult_invers_xt[i][j]=0.0;
            y_oc[j]=0.0;
        }
        for(int j=0; j<inData.dimFactor+1; j++){
            Invers[i][j]=0.0;
            mult_xt_w_x[i][j]=0.0;
        }
    }

    double **xT;
    xT = new double*[inData.dimFactor+1];

    for( int i=0; i<inData.dimFactor+1; i++ )
        xT[i]=new double[inData.dimExp];

    for( int i=0; i<inData.dimFactor+1; i++ )
        for( int j=0; j<inData.dimExp; j++ )
            xT[i][j] = 0.0;

    //вычисление транспонированной матрицы
    X_t = TranspositionMatrix(Xmat, xT);

    ofstream out_X_t("X_t.txt");
    out_X_t << "X_t" << endl;
    for(int i = 0; i < inData.dimFactor+1; i++)
    {
        for(int j = 0; j < inData.dimExp; j++)
            out_X_t << X_t[i][j] << "  \t";
        out_X_t << endl;
    }
    out_X_t << "\n";
    out_X_t.close();


    rezMult1 = new double*[inData.dimFactor+1];
    for (int i=0; i<inData.dimFactor+1; i++ )
        rezMult1[i] = new double[inData.dimExp];

    for (int i=0; i<inData.dimFactor+1; i++ )
        for (int j=0; j<inData.dimExp; j++ )
            rezMult1[i][j]=0.0;

    // произведение X транспонированной на W_mu
    mult_xt_w = MultMM1(X_t, W_mu, inData.dimFactor+1, inData.dimExp, inData.dimExp);

    ofstream out_mult_xt_w("mult_xt_w.txt");
    out_mult_xt_w << "mult_xt_w:" << endl;
    for (int i=0; i<inData.dimFactor+1; i++){
         for(int j = 0; j < inData.dimExp; j++)
             out_mult_xt_w << mult_xt_w[i][j] << "  \t";
        out_mult_xt_w << endl;
    }

    rezMult2 = new double*[inData.dimFactor+1];
    for (int i=0; i<inData.dimFactor+1; i++ )
        rezMult2[i] = new double[inData.dimFactor+1];

    for (int i=0; i<inData.dimFactor+1; i++ )
        for (int j=0; j<inData.dimFactor+1; j++ )
            rezMult2[i][j]=0.0;

    // произведение Xt*W_mu*X
    mult_xt_w_x = MultMM3(mult_xt_w, Xmat, inData.dimFactor+1, inData.dimExp, inData.dimFactor+1);

    ofstream out_mult_xt_w_x("mult_xt_w_x.txt");
    out_mult_xt_w_x << "mult_xt_w_x:" << endl;
    for (int i=0; i<inData.dimFactor+1; i++){
         for(int j = 0; j < inData.dimFactor+1; j++)
             out_mult_xt_w_x << mult_xt_w_x[i][j] << "  \t";
        out_mult_xt_w_x << endl;
    }

    //обращение матрицы
    Invers = PseudoInverse(mult_xt_w_x, inData.dimFactor+1);

    ofstream out_Invers("Invers.txt");
    out_Invers << "Invers" << endl;
    for(int i = 0; i < inData.dimFactor+1; i++)
    {
        for(int j = 0; j < inData.dimFactor+1; j++)
            out_Invers << Invers[i][j] << "  \t";
        out_Invers << endl;
    }
    out_Invers << "\n";
    out_Invers.close();


    for (int i=0; i<inData.dimFactor+1; i++)
        delete [] rezMult2[i];
    delete [] rezMult2;

    rezMult3 = new double*[inData.dimFactor+1];
    for (int i=0; i<inData.dimFactor+1; i++ )
        rezMult3[i] = new double[inData.dimExp];

    for (int i=0; i<inData.dimFactor+1; i++ )
        for (int j=0; j<inData.dimExp; j++ )
            rezMult3[i][j]=0.0;

    //произведение обратной на траспонированную
    mult_invers_xt = MultMM2(Invers, X_t, inData.dimExp, inData.dimFactor+1);

    ofstream out_mult_invers_xt("mult_invers_xt.txt");
    out_mult_invers_xt << "mult_invers_xt:" << endl;
    for (int i=0; i<inData.dimFactor+1; i++){
         for(int j = 0; j < inData.dimExp; j++)
             out_mult_invers_xt << mult_invers_xt[i][j] << "  \t";
        out_mult_invers_xt << endl;
    }

    for (int i=0; i<inData.dimFactor+1; i++ )
        for (int j=0; j<inData.dimExp; j++ )
            rezMult1[i][j]=0.0;

    // произведение всего снова на W
    mult_all_on_W = MultMM1(mult_invers_xt, W_mu, inData.dimFactor+1, inData.dimExp, inData.dimExp);

    ofstream out_mult_all_on_W("mult_all_on_W.txt");
    out_mult_all_on_W << "mult_all_on_W" << endl;
    for(int i = 0; i < inData.dimFactor+1; i++)
    {
        for(int j = 0; j < inData.dimExp; j++)
            out_mult_all_on_W << mult_all_on_W[i][j] << "  \t";
        out_mult_all_on_W << endl;
    }
    out_mult_all_on_W << "\n";
    out_mult_all_on_W.close();

    for (int i=0; i<inData.dimFactor+1; i++)
        delete [] rezMult3[i];
    delete [] rezMult3;


    tetta = MultMV_cluster();

    return 0;
}

//функция дефаззицикации отклика
void method::Deffazification()
{
    for(int i=0; i<inData.dimExp; i++)
        for(int j=0; j<cluster.Nc; j++)
            y_oc[i] += y_matrix[i][j] * cluster.mu_next[i][j];

    for(int i=0; i<inData.dimExp; i++)
    {
        mse += pow(y_oc[i] - y_no_noise[i], 2.0);//это у истинное - у оцененное
        cout << y_oc[i] << endl;}
    mse = fabs(mse * (1/(double)inData.dimExp));

    ofstream out_mse("mse.txt");
    out_mse << mse << endl;
    out_mse.close();

    ofstream out_deffazification("deffazification.txt");
    out_deffazification << "\t y\ty_oc \t " << endl;
    for(int i = 0; i < inData.dimExp; i++)
        out_deffazification << y_main[i] << "\t" << y_oc[i] << endl;
    out_deffazification.close();

    ofstream out_y_oc("y_oc.txt");
    for(int i = 0; i < inData.dimExp; i++)
        out_y_oc << y_oc[i]<< endl;
    out_y_oc.close();

}


//функция подсчета остаточной суммы квадратов RSS для одномерного случая
void method::RSS_one()
{		int flag = 0;
        double val = 0, val1 = 0;
            double sum1=0, sum2=0;
                    int tetta_el;//индекс вектора тетт
                    for(int sector_i = 0; sector_i < sector_n; sector_i++)//по каждому отрезку
                        {
                            if (inData.choiceFunction == 1)//если треугольники
                            {
                            for(int point_i = 0; point_i < D[sector_i].xx_one.size(); point_i++)//по всем точкам
                                {
                                    for(int mu_i = 0; mu_i < 2; mu_i++)//по количеству функций принадлежности
                                    {
                                        tetta_el = D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x);//индекс тетт

                                        double mu_val = D[sector_i].mu_val_tri_one(mu_i, D[sector_i].xx_one[point_i]);//значние функции принадлежности

                                        val += tetta[tetta_el+1] * mu_val * D[sector_i].xx_one[point_i];

                                    }
                                    val+=tetta[0];

                                    y_oc[D[sector_i].number_x_one[point_i]] = val;// вывод у оцененного
                                    val = 0;
                                }
                            }
                            if (inData.choiceFunction == 2)//если трапеции
                            {
                                if (flag == 0)//если не построили прямую, идем ее строить
                                {
                                    int mu_i = 0;
                                    for(int point_i = 0; point_i < D[sector_i].xx_one.size(); point_i++)//по всем точкам
                                    {
                                        int tetta_el = 2 * D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x);//индекс тетт
                                        double mu_val = D[sector_i].mu_val_tra_one(mu_i, D[sector_i].xx_one[point_i]);//значние функции принадлежности

                                        val = tetta[tetta_el] * mu_val + tetta[tetta_el+1] * mu_val * D[sector_i].xx_one[point_i];
                                        y_oc[D[sector_i].number_x_one[point_i]] = val;// вывод у оцененного
                                    }
                                    val = 0;
                                    flag = 1;
                                }
                                else//если построили  прямую, идем строить треугольники
                                {
                                    for(int point_i = 0; point_i < D[sector_i].xx_one.size(); point_i++)//по всем точкам в отрезке
                                    {
                                        for (int mu_i = 1; mu_i < 3; mu_i++)//участок, где рассматривается правая часть треугольника
                                        {
                                            int tetta_el = 2 * D[sector_i].mu_number_one(mu_i, sector_i, inData.choiceFunction, mu_numbers_x);//индекс тетт
                                            double mu_val = D[sector_i].mu_val_tra_one(mu_i, D[sector_i].xx_one[point_i]);//значние функции принадлежности

                                            val += tetta[tetta_el] * mu_val + tetta[tetta_el+1] * mu_val * D[sector_i].xx_one[point_i];
                                            if (val<0) val = -val;
                                            y_oc[D[sector_i].number_x_one[point_i]] = val;// вывод у оцененного

                                        }val = 0;
                                        flag = 0;
                                    }
                                }
                            }
                        }
    for(int i=0; i<inData.dimExp; i++)
        mse += pow(y_oc[i] - y_no_noise[i], 2.0);//это у истинное - у оцененное

    mse = fabs(mse * (1/(double)inData.dimExp));

    ofstream out_mse("mse.txt");
    out_mse << mse << endl;
    out_mse.close();

    ofstream out_rss("rss.txt");

    out_rss << "\t y \t / \t y_oc \t " << endl;
    for(int i = 0; i < inData.dimExp; i++)
        out_rss << y_main[i] << "\t" << y_oc[i] << endl;
    out_rss.close();

    ofstream out_y_oc("y_oc.txt");
    out_y_oc << "y_oc" << endl;
    for(int i = 0; i < inData.dimExp; i++)
        out_y_oc << y_oc[i]<< endl;
    out_y_oc.close();
    /*
    //подсчет относительной погрешности вектора у оцененное
    for(int i = 0; i < inData.dimExp; i++)
    {
        sum1 += (y_oc[i] - y_main[i])*(y_oc[i] - y_main[i]);
        sum2 += y_oc[i]*y_oc[i];
    }
    sum1 = sqrt(sum1/sum2);//относительная погрешность

    ofstream out_pogresh("pogreshnost.txt");
    out_pogresh << scientific;
    out_pogresh << "pogreshnost:" << endl;
        out_pogresh << sum1 << endl;
    out_pogresh.close();*/
}

//функция подсчета остаточной суммы квадратов RSS для двумерного случая
void method::RSS_two()
{

    int flag = 0;
    double val = 0, sum1 = 0, sum2 = 0;
    int tetta_el;
    y_no_noise = new double[inData.dimExp];

    for(int rect_i = 0; rect_i < rect_n; rect_i++) //по каждому прямоугольнику
    {
        if (inData.choiceFunction == 1)//если треугольники
        {
            for(int point_i = 0; point_i < C[rect_i].xx_two.size(); point_i++)//по всем точкам
            {
                for(int mu_i = 0; mu_i < 4; mu_i++)//по количеству функций принадлежности
                {
                    tetta_el = 2 * C[rect_i].mu_number_two(mu_i, rect_i, inData.choiceFunction, mu_numbers_x, mu_numbers_y)+1;//индекс тетт
                    double mu_val = C[rect_i].mu_val_tri_two(mu_i, C[rect_i].xx_two[point_i]);

                    //val - это окончательный подсчет игрек оцененного
                    val += tetta[tetta_el] * mu_val * C[rect_i].xx_two[point_i][0] + tetta[tetta_el+1] * mu_val * C[rect_i].xx_two[point_i][1];
                }
                val += tetta[0];
                y_oc[C[rect_i].number_x_two[point_i]] = val;// вывод у оцененного
                val = 0;
            }
        }
    }
    ofstream out_rss("rss.txt");
    //out_rss << scientific;
    out_rss << "\t y \t / \t y_oc \t " << endl;
    for(int i = 0; i < inData.dimExp; i++)
        out_rss << y_main[i] << "\t" << y_oc[i] << endl;
    out_rss.close();

    ofstream out_y_oc("y_oc.txt");
    out_y_oc << scientific;
    out_y_oc << "y_oc" << endl;
    for(int i = 0; i < inData.dimExp; i++)
        out_y_oc << y_oc[i] << endl;
    out_y_oc.close();

        //подсчет относительной погрешности вектора у оцененное
    for(int i = 0; i < inData.dimExp; i++)
    {
        sum1 += (y_oc[i] - y_main[i])*(y_oc[i] - y_main[i]);
        sum2 += y_oc[i]*y_oc[i];
    }
    sum1 = sqrt(sum1/sum2);//относительная погрешность

    ofstream out_pogresh("pogreshnost.txt");
    out_pogresh << scientific;
    out_pogresh << "pogreshnost:" << endl;
        out_pogresh << sum1 << endl;
    out_pogresh.close();


    //delete [] y_no_noise;
}

//подсчет коэффициента детерминации
double method::coefDetermination()
{
    R = 0.0;//коэффициент детерминации
    double summ1 = 0.0, summ2 = 0.0, summ3 = 0.0;

    for( int i=0; i<inData.dimExp; i++ )
    {
        summ1 += y_main[i] * y_oc[i];//произведение компонент векторов
        summ2 += y_main[i] * y_main[i];//произведение компонент первого вектора
        summ3 += y_oc[i] * y_oc[i];//произведение компонент второго вектора
    }

    R = summ1 / (sqrt(summ2) * sqrt(summ3));//cos(a,b) = скалярное произведение векторов/произведение сумм квадратов по компонентам вектора

    out_criterion << scientific;
    out_criterion << "R: " << R << "\n" << endl;
    out_criterion.close();

    return R;
}

//подсчет средней ошибки (CV)
double method::averageError_no_cluster()
{
    delta = 0;

    for(int i = 0; i < inData.dimExp; i++) {
        //считаем числитель
        double res1 = 0;
        for(int j = 0; j < inData.m_loc; j++) {
            res1 += Xmat[i][j] * tetta[j];
        }
        res1 = y_main[i] - res1;

        //считаем знаменатель
        double res2 = 0, sum = 0.;

        ofstream obr_xt("Invers.txt");
        obr_xt << "Invers" << endl;
        for(int i = 0; i < inData.m_loc; i++)
        {
            for(int j = 0; j < inData.m_loc; j++)
                obr_xt << Invers[i][j] << "  \t";
            obr_xt << endl;
        }
        obr_xt << "\n";
        obr_xt.close();

        double f=0.0;

        for(int j = 0; j < inData.m_loc; j++)
        {
            tempvect[j] = 0.0;
            for(int k = 0; k < inData.m_loc; k++)
                tempvect[j] = Xmat[i][k] * Invers[k][j];


            sum += tempvect[j] * Xmat[i][j];
        }
        res2 = 1 - sum;
    delta += (res1*res1)/(res2*res2);
    }

    delta /= inData.dimExp;

    out_criterion << "CV: " << delta << endl;
    out_criterion.close();



    return delta;
}

//подсчет средней ошибки (CV)
double method::averageError_with_cluster()
{
    delta = 0;
    delta_fin = 0;
    double *tempvect;
    double rez_temp = 0.0, res1 = 0.0;
    tempvect = new double[inData.dimFactor+1];

    mult_xt_x = new double*[inData.dimFactor+1];
    inverse_xt_x = new double*[inData.dimFactor+1];

    for (int i=0; i<inData.dimFactor+1; i++ ){
        mult_xt_x[i] = new double[inData.dimFactor+1];
        inverse_xt_x[i] = new double[inData.dimFactor+1];
    }

    for (int i=0; i<inData.dimFactor+1; i++ )
        for (int f=0; f<inData.dimFactor+1; f++ ){
            mult_xt_x[i][f] = 0.0;
            inverse_xt_x[i][f]=0.0;
            rezMult1[i][f] = 0.0;
        }

    //произведение X транспонированной на Xmat
    mult_xt_x = MultMM1(X_t, Xmat, inData.dimFactor+1, inData.dimExp, inData.dimFactor+1);

    ofstream out_mult_xt_x("mult_xt_x.txt");
    out_mult_xt_x << "mult_xt_x:" << endl;
    for (int i=0; i<inData.dimFactor+1; i++){
        for(int j = 0; j < inData.dimFactor+1; j++)
             out_mult_xt_x << mult_xt_x[i][j] << "  \t";
        out_mult_xt_x << endl;
    }

    //обращение матрицы
    inverse_xt_x = PseudoInverse(mult_xt_x, inData.dimFactor+1);

    ofstream out_inverse_xt_x("inverse_xt_x.txt");
    out_inverse_xt_x << "inverse_xt_x:" << endl;
    for (int i=0; i<inData.dimFactor+1; i++){
        for(int j = 0; j < inData.dimFactor+1; j++)
             out_inverse_xt_x << inverse_xt_x[i][j] << "  \t";
        out_inverse_xt_x << endl;
    }

    for(int k=0;k<cluster.Nc;k++){

        for(int i = 0; i < inData.dimExp; i++) {
            //считаем числитель
            rez_temp = 0, res1 = 0;
            for(int j = 0; j < inData.dimFactor+1; j++)
                rez_temp += Xmat[i][j] * tetta_matrix[j][k];

        res1 = y_main[i] - rez_temp;

        //считаем знаменатель
        double res2 = 0, sum = 0.;

        for(int j = 0; j < inData.dimFactor+1; j++)
        {
            tempvect[j] = 0.;
            for(int h = 0; h < inData.dimFactor+1; h++)
                tempvect[j] += Xmat[i][h] * inverse_xt_x[h][j];

            sum += tempvect[j] * Xmat[i][j];
        }
        res2 = 1 - sum;
    delta += (res1*res1)/(res2*res2);

    }

        delta_fin += delta/inData.dimExp;
        delta = 0;
    }//конец цикла по кластерам

    out_criterion << "CV: " << delta_fin << endl;
    out_criterion.close();

    for (int i=0; i<inData.dimFactor+1; i++ ){
        delete mult_xt_x[i];
        delete inverse_xt_x[i];
        //delete rezMult1[i];
    }

    delete [] tempvect;
    delete [] mult_xt_x;
    delete [] inverse_xt_x;
    //delete [] rezMult1;

    return delta_fin;
}

double method::PYTHAG(double a, double b)
{
    double at = fabs(a), bt = fabs(b), ct, result;
    if (at > bt)
    {
        ct = bt / at;
        result = at * sqrt(1.0 + ct * ct);
    }
    else if (bt > 0.0)
    {
        ct = at / bt;
        result = bt * sqrt(1.0 + ct * ct);
    }
    else result = 0.0;
    return(result);
}

void method::sort_sv(int m, int n, int k, double **a, double *w, double **v)
{
    int i, j;
    for (i = k; (i < n - 1) && (w[i] < w[i+1]); i++)
    {
        swap(w[i], w[i+1]);
        for (j = 0; j < m; j++) swap(a[j][i], a[j][i+1]);
        for (j = 0; j < n; j++) swap(v[j][i], v[j][i+1]);
    }
}

double method::Max(double a, double b)
{
    if(a > b)
        return a;
    return b;
}
double method::SIGN(double a, double b)
{
    if(b >= 0.0)
        return fabs(a);
    return -fabs(a);
}

int method::svdcmp(double **a, int m, int n, double *w, double **v)
{
    int flag, its;
    long i, k, l;  /* These must be signed */
    int j, jj, nm;
    double c, f, h, s, x, y, z;
    double anorm = 0.0, g = 0.0, scale = 0.0;

    if (m < n) return(false);  /* flag an error if m < n */

    double * rv1 = new double [n];

    /* Householder reduction to bidiagonal form */
    for (i = 0; i < n; i++)
    {

        /* left-hand reduction */
        l = i + 1;
        rv1[i] = scale * g;
        g = s = scale = 0.0;
        if (i < m)
        {
            for (k = i; k < m; k++) scale += fabs(a[k][i]);
            if (scale)
            {
                for (k = i; k < m; k++)
                {
                    a[k][i] /= scale;
                    s += a[k][i] * a[k][i];
                }
                f = a[i][i];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                a[i][i] = f - g;
                if (i != n - 1)
                {
                    for (j = l; j < n; j++)
                    {
                        for (s = 0.0, k = i; k < m; k++) s += a[k][i] * a[k][j];
                        f = s / h;
                        for (k = i; k < m; k++) a[k][j] += f * a[k][i];
                    }
                }
                for (k = i; k < m; k++) a[k][i] *= scale;
            }
        }
        w[i] = scale * g;

        /* right-hand reduction */
        g = s = scale = 0.0;
        if (i < m && i != n - 1)
        {
            for (k = l; k < n; k++) scale += fabs(a[i][k]);
            if (scale)
            {
                for (k = l; k < n; k++)
                {
                    a[i][k] /= scale;
                    s += a[i][k] * a[i][k];
                }
                f = a[i][l];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                a[i][l] = f - g;
                for (k = l; k < n; k++) rv1[k] = a[i][k] / h;
                if (i != m - 1)
                {
                    for (j = l; j < m; j++)
                    {
                        for (s = 0.0, k = l; k < n; k++) s += a[j][k] * a[i][k];
                        for (k = l; k < n; k++) a[j][k] += s * rv1[k];
                    }
                }
                for (k = l; k < n; k++) a[i][k] *= scale;
            }
        }
        anorm = Max(anorm, (fabs(w[i]) + fabs(rv1[i])));
    }

    /* accumulate the right-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            if (g)
            {
                for (j = l; j < n; j++)
                    v[j][i] = (a[i][j] / a[i][l]) / g;

                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < n; k++) s += a[i][k] * v[k][j];
                    for (k = l; k < n; k++) v[k][j] += s * v[k][i];
                }
            }
            for (j = l; j < n; j++) v[i][j] = v[j][i] = 0.0;
        }
        v[i][i] = 1.0;
        g = rv1[i];
        l = i;
    }

    /* accumulate the left-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        l = i + 1;
        g = w[i];
        if (i < n - 1)
            for (j = l; j < n; j++) a[i][j] = 0.0;
        if (g)
        {
            g = 1.0 / g;
            if (i != n - 1)
            {
                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < m; k++) s += a[k][i] * a[k][j];
                    f = (s / a[i][i]) * g;
                    for (k = i; k < m; k++) a[k][j] += f * a[k][i];
                }
            }
            for (j = i; j < m; j++) a[j][i] *= g;
        }
        else
        {
            for (j = i; j < m; j++) a[j][i] = 0.0;
        }
        ++a[i][i];
    }

    /* diagonalize the bidiagonal form */
    for (k = n - 1; k >= 0; k--)         /* loop over singular values */
    {
        for (its = 0; its < 30; its++)     /* loop over allowed iterations */
        {
            flag = 1;
            for (l = k; l >= 0; l--)         /* test for splitting */
            {
                nm = l - 1;
                if (fabs(rv1[l]) + anorm == anorm)
                {
                    flag = 0;
                    break;
                }
                if (fabs(w[nm]) + anorm == anorm) break;
            }
            if (flag)
            {
                c = 0.0;
                s = 1.0;
                for (i = l; i <= k; i++)
                {
                    f = s * rv1[i];
                    if (fabs(f) + anorm != anorm)
                    {
                        g = w[i];
                        h = PYTHAG(f, g);
                        w[i] = h;
                        if (h == 0.0)
                        {
                            char s[100];
                            //sprintf(s, "h = %f, f = %f, g = %f\n", h, f, g);
                            fprintf(stdout,"%s",s);
                        }
                        h = 1.0 / h;
                        c = g * h;
                        s = (- f * h);
                        for (j = 0; j < m; j++)
                        {
                            y = a[j][nm];
                            z = a[j][i];
                            a[j][nm] = y * c + z * s;
                            a[j][i] = z * c - y * s;
                        }
                    }
                }
            }
            z = w[k];
            if (l == k)          /* convergence */
            {
                if (z < 0.0)       /* make singular value nonnegative */
                {
                    w[k] = -z;
                    for (j = 0; j < n; j++) v[j][k] = (-v[j][k]);
                }
                sort_sv(m, n, k, a, w, v);
                break;
            }
            if (its >= 30)
            {
                delete [] rv1;
                return(false);     /* return an error flag */
            }

            /* shift from bottom 2 x 2 minor */
            x = w[l];
            nm = k - 1;
            y = w[nm];
            g = rv1[nm];
            h = rv1[k];
            f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
            g = PYTHAG(f, 1.0);
            f = ((x - z) * (x + z) + h * ((y / (f + SIGN(g, f))) - h)) / x;

            /* next QR transformation */
            c = s = 1.0;
            for (j = l; j <= nm; j++)
            {
                i = j + 1;
                g = rv1[i];
                y = w[i];
                h = s * g;
                g = c * g;
                z = PYTHAG(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y = y * c;
                for (jj = 0; jj < n; jj++)
                {
                    x = v[jj][j];
                    z = v[jj][i];
                    v[jj][j] = x * c + z * s;
                    v[jj][i] = z * c - x * s;
                }
                z = PYTHAG(f, h);
                w[j] = z;
                if (z)
                {
                    z = 1.0 / z;
                    c = f * z;
                    s = h * z;
                }
                f = (c * g) + (s * y);
                x = (c * y) - (s * g);
                for (jj = 0; jj < m; jj++)
                {
                    y = a[jj][j];
                    z = a[jj][i];
                    a[jj][j] = y * c + z * s;
                    a[jj][i] = z * c - y * s;
                }
            }
            rv1[l] = 0.0;
            rv1[k] = f;
            w[k] = x;
        }
    }

    delete [] rv1;
    return(true);
}

double **method::PseudoInverse(double ** A, int N)
{
    // A - это U
    double ** U = new double * [N];
    for(int i = 0; i < N; i++)
    {
        U[i] = new double [N];
        for(int j = 0; j < N; j++)
            U[i][j] = A[i][j];
    }

    double ** V = new double * [N];
    for(int i = 0; i < N; i++)
        V[i] = new double [N];

    double * W = new double [N];

    svdcmp(U, N, N, W, V);

    double ** A_inv = new double * [N];
    for(int i = 0; i < N; i++)
    {
        A_inv[i] = new double [N];
    }

    // Поиск эпсилон
    double max_w = W[0];
    for(int i = 1; i < N; i++)
        if(fabs(W[i]) > max_w) max_w = fabs(W[i]);
    double epsilon = DBL_EPSILON * max_w * N;

    // Поиск W+
    for(int i = 0; i < N; i++)
    {
        if(W[i] > epsilon)
            W[i] = 1.0 / W[i];
        else
            W[i] = 0.0;
    }

    // Поиск V * W+
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            V[i][j] *= W[j];

    // Поиск V * W+ * U*
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            A_inv[i][j] = 0.0;
            for(int k = 0; k < N; k++)
            {
                A_inv[i][j] += V[i][k] * U[j][k];
            }
        }

    // Чистим память
    for(int i = 0; i < N; i++)
    {
        delete [] U[i];
        delete [] V[i];
    }
    delete [] U;
    delete [] V;
    delete [] W;

    return A_inv;
}

double clustering::PYTHAG_cluster(double a, double b)
{
    double at = fabs(a), bt = fabs(b), ct, result;
    if (at > bt)
    {
        ct = bt / at;
        result = at * sqrt(1.0 + ct * ct);
    }
    else if (bt > 0.0)
    {
        ct = at / bt;
        result = bt * sqrt(1.0 + ct * ct);
    }
    else result = 0.0;
    return(result);
}

void clustering::sort_sv_cluster(int m, int n, int k, double **a, double *w, double **v)
{
    int i, j;
    for (i = k; (i < n - 1) && (w[i] < w[i+1]); i++)
    {
        swap(w[i], w[i+1]);
        for (j = 0; j < m; j++) swap(a[j][i], a[j][i+1]);
        for (j = 0; j < n; j++) swap(v[j][i], v[j][i+1]);
    }
}

double clustering::Max_cluster(double a, double b)
{
    if(a > b)
        return a;
    return b;
}
double clustering::SIGN_cluster(double a, double b)
{
    if(b >= 0.0)
        return fabs(a);
    return -fabs(a);
}

int clustering::svdcmp_cluster(double **a, int m, int n, double *w, double **v)
{
    int flag, its;
    long i, k, l;  /* These must be signed */
    int j, jj, nm;
    double c, f, h, s, x, y, z;
    double anorm = 0.0, g = 0.0, scale = 0.0;

    if (m < n) return(false);  /* flag an error if m < n */

    double * rv1 = new double [n];

    /* Householder reduction to bidiagonal form */
    for (i = 0; i < n; i++)
    {

        /* left-hand reduction */
        l = i + 1;
        rv1[i] = scale * g;
        g = s = scale = 0.0;
        if (i < m)
        {
            for (k = i; k < m; k++) scale += fabs(a[k][i]);
            if (scale)
            {
                for (k = i; k < m; k++)
                {
                    a[k][i] /= scale;
                    s += a[k][i] * a[k][i];
                }
                f = a[i][i];
                g = -SIGN_cluster(sqrt(s), f);
                h = f * g - s;
                a[i][i] = f - g;
                if (i != n - 1)
                {
                    for (j = l; j < n; j++)
                    {
                        for (s = 0.0, k = i; k < m; k++) s += a[k][i] * a[k][j];
                        f = s / h;
                        for (k = i; k < m; k++) a[k][j] += f * a[k][i];
                    }
                }
                for (k = i; k < m; k++) a[k][i] *= scale;
            }
        }
        w[i] = scale * g;

        /* right-hand reduction */
        g = s = scale = 0.0;
        if (i < m && i != n - 1)
        {
            for (k = l; k < n; k++) scale += fabs(a[i][k]);
            if (scale)
            {
                for (k = l; k < n; k++)
                {
                    a[i][k] /= scale;
                    s += a[i][k] * a[i][k];
                }
                f = a[i][l];
                g = -SIGN_cluster(sqrt(s), f);
                h = f * g - s;
                a[i][l] = f - g;
                for (k = l; k < n; k++) rv1[k] = a[i][k] / h;
                if (i != m - 1)
                {
                    for (j = l; j < m; j++)
                    {
                        for (s = 0.0, k = l; k < n; k++) s += a[j][k] * a[i][k];
                        for (k = l; k < n; k++) a[j][k] += s * rv1[k];
                    }
                }
                for (k = l; k < n; k++) a[i][k] *= scale;
            }
        }
        anorm = Max_cluster(anorm, (fabs(w[i]) + fabs(rv1[i])));
    }

    /* accumulate the right-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            if (g)
            {
                for (j = l; j < n; j++)
                    v[j][i] = (a[i][j] / a[i][l]) / g;

                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < n; k++) s += a[i][k] * v[k][j];
                    for (k = l; k < n; k++) v[k][j] += s * v[k][i];
                }
            }
            for (j = l; j < n; j++) v[i][j] = v[j][i] = 0.0;
        }
        v[i][i] = 1.0;
        g = rv1[i];
        l = i;
    }

    /* accumulate the left-hand transformation */
    for (i = n - 1; i >= 0; i--)
    {
        l = i + 1;
        g = w[i];
        if (i < n - 1)
            for (j = l; j < n; j++) a[i][j] = 0.0;
        if (g)
        {
            g = 1.0 / g;
            if (i != n - 1)
            {
                for (j = l; j < n; j++)
                {
                    for (s = 0.0, k = l; k < m; k++) s += a[k][i] * a[k][j];
                    f = (s / a[i][i]) * g;
                    for (k = i; k < m; k++) a[k][j] += f * a[k][i];
                }
            }
            for (j = i; j < m; j++) a[j][i] *= g;
        }
        else
        {
            for (j = i; j < m; j++) a[j][i] = 0.0;
        }
        ++a[i][i];
    }

    /* diagonalize the bidiagonal form */
    for (k = n - 1; k >= 0; k--)         /* loop over singular values */
    {
        for (its = 0; its < 30; its++)     /* loop over allowed iterations */
        {
            flag = 1;
            for (l = k; l >= 0; l--)         /* test for splitting */
            {
                nm = l - 1;
                if (fabs(rv1[l]) + anorm == anorm)
                {
                    flag = 0;
                    break;
                }
                if (fabs(w[nm]) + anorm == anorm) break;
            }
            if (flag)
            {
                c = 0.0;
                s = 1.0;
                for (i = l; i <= k; i++)
                {
                    f = s * rv1[i];
                    if (fabs(f) + anorm != anorm)
                    {
                        g = w[i];
                        h = PYTHAG_cluster(f, g);
                        w[i] = h;
                        if (h == 0.0)
                        {
                            char s[100];
                            //sprintf(s, "h = %f, f = %f, g = %f\n", h, f, g);
                            fprintf(stdout,"%s",s);
                        }
                        h = 1.0 / h;
                        c = g * h;
                        s = (- f * h);
                        for (j = 0; j < m; j++)
                        {
                            y = a[j][nm];
                            z = a[j][i];
                            a[j][nm] = y * c + z * s;
                            a[j][i] = z * c - y * s;
                        }
                    }
                }
            }
            z = w[k];
            if (l == k)          /* convergence */
            {
                if (z < 0.0)       /* make singular value nonnegative */
                {
                    w[k] = -z;
                    for (j = 0; j < n; j++) v[j][k] = (-v[j][k]);
                }
                sort_sv_cluster(m, n, k, a, w, v);
                break;
            }
            if (its >= 30)
            {
                delete [] rv1;
                return(false);     /* return an error flag */
            }

            /* shift from bottom 2 x 2 minor */
            x = w[l];
            nm = k - 1;
            y = w[nm];
            g = rv1[nm];
            h = rv1[k];
            f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
            g = PYTHAG_cluster(f, 1.0);
            f = ((x - z) * (x + z) + h * ((y / (f + SIGN_cluster(g, f))) - h)) / x;

            /* next QR transformation */
            c = s = 1.0;
            for (j = l; j <= nm; j++)
            {
                i = j + 1;
                g = rv1[i];
                y = w[i];
                h = s * g;
                g = c * g;
                z = PYTHAG_cluster(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y = y * c;
                for (jj = 0; jj < n; jj++)
                {
                    x = v[jj][j];
                    z = v[jj][i];
                    v[jj][j] = x * c + z * s;
                    v[jj][i] = z * c - x * s;
                }
                z = PYTHAG_cluster(f, h);
                w[j] = z;
                if (z)
                {
                    z = 1.0 / z;
                    c = f * z;
                    s = h * z;
                }
                f = (c * g) + (s * y);
                x = (c * y) - (s * g);
                for (jj = 0; jj < m; jj++)
                {
                    y = a[jj][j];
                    z = a[jj][i];
                    a[jj][j] = y * c + z * s;
                    a[jj][i] = z * c - y * s;
                }
            }
            rv1[l] = 0.0;
            rv1[k] = f;
            w[k] = x;
        }
    }

    delete [] rv1;
    return(true);
}

void method::clear_memory()
{
    cluster.tmp.clear();

    for (int k=0; k<cluster.Nc; k++)
    {
        delete [] cluster.v[k];
        delete [] cluster.mu_prev_transp[k];
    }

    for (int k=0; k<cluster.N; k++)
    {
        //delete [] cluster.d[k];
        delete [] cluster.mu_prev[k];
        delete [] cluster.mu_next[k];
        delete [] Xmat[k];
        delete [] cluster.x[k];
        delete [] cluster.mult_X_V[k];
        //delete [] y_matrix[k];
    }

    delete [] cluster.mu_prev_transp;
    delete [] cluster.dop_sum1;
    delete [] cluster.dop_sum2;
    delete [] cluster.x;
    delete [] cluster.mult_X_V;
    delete [] cluster.mu_prev;
    delete [] cluster.mu_next;
    //delete [] cluster.d;	delete [] cluster.v;	delete [] y_matrix;


    for (int i=0; i<inData.dimFactor+1; i++)
    {
        delete [] X_t[i];
        delete [] Invers[i];
        delete [] tetta_matrix[i];
        //delete [] mult_xt_w[i];	delete [] mult_xt_w_x[i];	delete [] mult_all_on_W[i];	delete [] mult_invers_xt[i];
    }

    delete [] X_t;
    delete [] Invers;
    delete [] rezMult_onY;
    delete [] tetta_matrix;
    delete [] y_oc;
    delete [] y_no_noise;
    //delete [] mult_xt_w;	delete [] mult_xt_w_x;	delete [] tetta;	delete [] mult_all_on_W;	delete [] mult_invers_xt;
}
