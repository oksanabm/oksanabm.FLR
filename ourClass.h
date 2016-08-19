
#pragma once

#include<vector>
#include<cstdio>
#include<iostream>// заголовочный файл с классами, функциями и переменными для организации ввода-вывода в языке программирования C++
#include<fstream>//заголовочный файл из стандартной библиотеки C++, включающий набор классов, методов и функций, которые предоставляют интерфейс для чтения/записи данных из/в файл
#include<cstdlib>//содержит в себе функции, занимающиеся выделением памяти, контроль процесса выполнения программы, преобразования типов и другие
#include<cmath>
#include<float.h>
#include<utility>
#include<time.h>
#include <algorithm>
#include <cfloat>
#include <QTimer>
#include <QTime>


using namespace std;

class inputData										//предназначен для хранения данных эксперимента
{
public:
    int dimExp;										//количество экспериментов
    int dimFactor;									//количество входных переменных
    double level_noise;								//уровень шума
    double disperss;								//значение дисперсии
    int choiceFunction;								//вид функций принадлежности
    int numberRules;								//количество правил
    int numberFunction;
    int m_loc;										//размерность
    double granic[2][2];							//границы варьирования факторов
    vector < pair<double,double> >  var_borders;	//ограничения на уровни варьирования факторов

     int flag_about_free;							//флаг, обозначающий присутствие нескольких свободных членов или отсутствие
};

class sector										//предназначен для формирования сетки отрезков для одномерного случая
{
public:
    double a, b;									//границы отрезка
    int number_a, number_b;							//номера точек
    vector<double> xx_one;							//вектор координат
    vector<int> number_x_one;						//вектор номеров точек
    int n_x;										//количество точек по оси х
    int mu_number_one(int i, int j, int choiceFunc,int **mu_loc_number);//номер функции принадлежности
    double mu_val_tri_one(int i, double x);			//значение функции принадлежности в точке (ТРЕУГОЛЬНИКИ)
    double mu_val_tra_one(int i, double x);			//значение функции принадлежности в точке (ТРАПЕЦИИ)
    bool in_sector(double x);						//функция проверки вхождения точки в отрезок
};

class rectangle										//предназначен для формирования сетки прямоугольников для двумерного случая
{
public:
    double a[2], b[2];								//массивы для хранения начала и конца отрезков
    int number_a[2], number_b[2];					//номера
    vector<double*> xx_two;							//вектор координат
    vector<int> number_x_two;						//вектор номеров вершин
    int n_x, n_y;									//количество точек по оси х и по оси у
    int mu_number_two(int numb, int j, int choiceFunc, int **mu_loc_number_x, int **mu_loc_number_y);//номер функции принадлежности
    double mu_val_tri_two(int i, double* x);		//значение функции принадлежности в точке (ТРЕУГОЛЬНИКИ)
    bool in_rect(double* x);						//функция проверки вхождения точки в прямоугольни
};

class clustering									//кластеризация данных
{
public:
    int Nc,											//количество кластеров
        N,											//количество наблюдений
        flag_clustering,							//флаг о методе кластеризации 1-fcm, 2-GK
        w,											//экспоненциальный вес
        dim;										//размерность пространства факторов
    double eps;										//параметр останова
    double d_in_pow;
    double **mu_prev,								//матрица разбиения на предыдущем шаге
           **mu_prev_transp,						//дополнительный массив для перезаписи ФП
           **mu_next;								//матрица разбиения на текущем шаге
    double **v,										//центры кластеров
           **x,										//наблюдения
            **mult_X_V,
            **rez_mult_X_V,
            **difference_X_V,
            **difference_X_V_matrix,
            **tmp_numerator_formula,
            **tmp_numerator_formula2,
            **rez_mult_mu_XV,
            **cov_matrix_obr,
            **tmp_d;
    vector<double> tmp;								//вектор для расстояний
    vector<double> tmp_for_dist;
    vector<double> distance;
    vector<vector<double>> cov_matrix;				//ковариационная матрица
    vector<vector<double>> scale_matrix;			//матрица масштаба
    vector< vector<vector<double>>> v_cov_matrix;	//вектор ковариационных матриц
    vector< vector<vector<double>>> v_scale_matrix;	//вектор матриц масштаба
    vector<vector<double>> vector_matrix_distance;	//вектор матриц масштаба
    double **d,										//расстояния
            ch;
    long double summ;
    double **A_inv;
    double mu_summ1, mu_summ2, mu_sum;				//вспомогательные переменные
    double *dop_sum1, *dop_sum2;					//вспомогательные переменные
                                                    //общие
        void newData();										//выделение памяти
        void begin_U();										//инифиализация начальной матрицы функций принадлежности
        void centerCluster();								//подсчет центров кластеров
        double generationNumberRAV(double min,double max);	//генерация RAv чисел
                                                    //для fcm
        void Mu_Calc_fcm();									//функции принадлежности для фсм
        void distanse_fcm();								//расстояния для фсм
                                                    //для GK
        void matrix_covariance_GK();			//матрица ковариации
        double det_matrix_covariance_GK(vector<vector<double>> mas, int dimention);
        void GetMatr(vector<vector<double>> mas, double **p, int i, int j, int m);
        void matrix_scale_GK();
        double **PseudoInverse_cluster(vector<vector<double>> A, int N);
        double PYTHAG_cluster(double a, double b);
        void sort_sv_cluster(int m, int n, int k, double **a, double *w, double **v);
        double Max_cluster(double a, double b);
        double SIGN_cluster(double a, double b);
        int svdcmp_cluster(double **a, int m, int n, double *w, double **v);
        void distance_GK();
        vector<double> mult_difference_X_V_matrix_v_scale_matrix(int number_cluster);
        void Mu_Calc_GK();									//функции принадлежности для густафсона-кесселя
};

class method
{
public:
   // double *x_one;									//объявление массива для одного фактора
    int flag_about_clustering;
    double **x_var;									//матрица факторов для многомерного случая с кластеризацией
    double **x_two;									//объявление массива для двух факторов
    double *y_main;									//отклик
    double *y_oc;									//вектор отклика оцененный
    double* y_no_noise;								//разница векторов отлика
    double mse;										//MSE
    double **y_matrix;								//матрица отклика дл всех кластеров
    double **tetta_matrix;							//матрица оценок дл всех кластеров
    double *tetta;									//оцениваемые параметры
    double **Xmat;									//матрица наблюдений
    double **W_mu;									//диагональная матрица весов
    double **x_for_graphic;							//сгенерированные числа для построения графиков
    double averageError_no_cluster();							//подсчет среднего для критерия скользящего контроля
    double e;										//ошибка
    double disperss;								//дисперсия для зашумления отклика
    double R;										//коэффициент детерминации
    double delta;									//для CV
    double delta_fin;								//для CV
    double **X_t;									//массив под матрицу транспонированную
    double **mult_xt_x;								//матрица произведения Хтранспонированную на Х
    double **xInvers;
    double **inverse_xt_x;							//произведение обратной на Х
    double **mult_xt_w;								//матрица произведения Хтранспонированная*Х
    double **Invers;								//матрица обратная
    double **mult_invers_xt;						//произведение обратной на Хт
    double **mult_all_on_W;							//умножение на весовую матрицу
    double **mult_xt_w_x;							//матрица (обратная*транпонированная)
    double *rezMult_onY;							//результат произведения матрицы на вектор
    bool SLAU_solution_Gauss(double **A, double **I, double **Xr, int m);//СЛАУ по гауссу
    bool trianglematrix1(double **Atr, double **Xtr, int m);			 //приведение к треугольному виду
    void transf1(double **Aa, double **Xx, int i, int m, double &A_d);	 //перестановка строк
    int n_x, n_y;									//количество отрезков по оси х, по оси у
    ifstream input_grid1,input_grid2;				//потоки дл считывания точек ФП
    inputData inData;								//объект класса входные данные
    rectangle *C;									//объект класса прямоугольник
    sector *D;										//объект класса сектор (отрезок)
    clustering cluster;								//объект класса кластеризации
    int rect_n;										//количество прямоугольников
    int sector_n;									//количество отрезков
    int number_mu;									//количество функций принадлежности
    int number_FP(int n_x, int n_y);				//количество функций принадлежности
    int loc_number_mu;								//количество номеров ФП
    int **mu_numbers_x;								//номера по оси х
    int **mu_numbers_y;								//номера по оси y
        double *tempvect;
                                            //моделирование данных
    void initialization_one_multi();						//инициализатор для одного фактора или нескольких для кластеризации
    void initialization_two();						//инициализатор для двух факторов
    void initialization_one();
                                            //построение сетки
    void buildGridFactorOne();						//для одного фактора
    void buildGridFactorTwo();						//для двух фактора

    double currentFunction(int i);			//выбор текущей функции отклика для моделирования данных
                                            //генераторы
    double generationNumberRAV(double min,double max);				//генератор случайных чисел по равномерному закону
    double generationNumberNORMAL(double mathWait, double sigma2);  //генератор случайных чисел по нормальному закону

                                            //функции построения матрицы наблюдений
    void constructMatrixX_one_tri();				//для одного фактора для ТРЕУГОЛЬНИКОВ
    void constructMatrix_cluster();			//для одного фактора с кластеризацией
    void constructMatrixX_two_tri();				//для двух факторов для ТРЕУГОЛЬНИКОВ
    void constructMatrixX_one_tra();				//для одного фактора для ТРАПЕЦИЙ

                                            //функции, необходимые для МНК
    double **TranspositionMatrix(double **xx, double **xTT);		//функция транпонирования матрицы
    double **InversionMatrix();						//обращение матрицы
                                            //некоторые функции для обращения матрицы
    double PYTHAG(double a, double b);
void sort_sv(int m, int n, int k, double **a, double *w, double **v);
    double Max(double a, double b);
    double SIGN(double a, double b);
    int svdcmp(double **a, int m, int n, double *w, double **v);
    double ** PseudoInverse(double ** A, int N);

    double **rezMult1;						//вспомогательные массивы
    double **rezMult2;						//вспомогательные массивы
    double **rezMult3;						//вспомогательные массивы
    double **MultMM1(double **x1, double **x2, int n, int m, int l);	//функция перемножения матрицы на матрицу (конкретно транпонированной на прямую)
    double **MultMM2(double **x1, double **x2, int n, int m);			//функция перемножения матрицы на матрицу (конкретно обратной на транспонированную)
    double **MultMM3(double **x1, double **x2, int n, int m, int l);

    double *MultMV(int m_loc, double *rezMult_mv);						//функция перемножения матрицы на вектор у
    double *MultMV_cluster();
   double *rezMult_mv;//результат произведения матрицы на вектор
    void Tetta();							//функция получения вектора тетт
    double Tetta_cluster(int k);			//получение оценок в случае с кластеризацией

                                            //критерий качества: остаточная сумма квадратов:
    double averageError_with_cluster();
    void Deffazification();							//для однофакторной модели
    void RSS_one();
    void RSS_two();									//для двуфакторной модели
    double coefDetermination();						//подсчет коэффициента детерминации

    void clear();
    void clear_memory();//очистка
    method();//конструктор
    ~method();//деструктор
};

