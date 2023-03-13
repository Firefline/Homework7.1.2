// Homework7.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

class VSumm
{
protected:
    int elements_num = 0;
    
    std::vector<int> v_1;
    std::vector<int> v_2;
    std::vector<int> v_summ;

public:
    VSumm(int elements_num)
    {
        this->elements_num = elements_num;
        for (int i = 0; i <= elements_num; ++i)
        {
            v_1.push_back(i);
            v_2.push_back(i+1);
            v_summ.push_back(i * 0);
        }
    }
    void vector_summ(int start, int finish)
    {
        for (int i = start; i <= finish; ++i)
        {
            v_summ[i] = v_1[i] + v_2[i];
        }
    }
    void cleaning()
    {
        for (int i = 0; i <= elements_num; ++i)
        {
            v_1[i] = i;
            v_2[i] = i + 1;
            v_summ[i] = 0;
        }
    }
    void print()
    {
        std::cout << v_1[elements_num] << "\t" << v_2[elements_num] << "\t" << v_summ[elements_num] << std::endl;;
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    VSumm vsumm_1(1000);
    VSumm vsumm_2(10000);
    VSumm vsumm_3(100000);
    VSumm vsumm_4(1000000);

    unsigned int n = std::thread::hardware_concurrency();

    //1 ПОТОК----------------------------------------------------------------

    auto start_1 = std::chrono::steady_clock::now();
    vsumm_1.vector_summ(0, 1000);
    auto end_1 = std::chrono::steady_clock::now();

    auto start_2 = std::chrono::steady_clock::now();
    vsumm_2.vector_summ(0, 10000);
    auto end_2 = std::chrono::steady_clock::now();

    auto start_3 = std::chrono::steady_clock::now();
    vsumm_3.vector_summ(0, 100000);
    auto end_3 = std::chrono::steady_clock::now();

    auto start_4 = std::chrono::steady_clock::now();
    vsumm_4.vector_summ(0, 1000000);
    auto end_4 = std::chrono::steady_clock::now();

    std::cout << "Количество аппаратных ядер: " << n << std::endl;
    std::cout << std::endl;
    std::chrono::duration<double> elapsed_seconds_1 = end_1 - start_1;
    std::chrono::duration<double> elapsed_seconds_2 = end_2 - start_2;
    std::chrono::duration<double> elapsed_seconds_3 = end_3 - start_3;
    std::chrono::duration<double> elapsed_seconds_4 = end_4 - start_4;
    std::cout << "\t\t" << "1000\t\t" << "10000\t\t" << "100000\t\t" << "1000000" << std::endl;
    std::cout << "1 поток  \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;

    vsumm_1.cleaning();
    vsumm_2.cleaning();
    vsumm_3.cleaning();
    vsumm_4.cleaning();
    //2 ПОТОКА----------------------------------------------------------------

    start_1 = std::chrono::steady_clock::now();
    vsumm_1.vector_summ(0, 500);
    std::thread t2_1(&VSumm::vector_summ, &vsumm_1, 501, 1000);
    end_1 = std::chrono::steady_clock::now();

    t2_1.join();

    start_2 = std::chrono::steady_clock::now();
    vsumm_2.vector_summ(0, 5000);
    std::thread t2_2(&VSumm::vector_summ, &vsumm_2, 5001, 10000);
    end_2 = std::chrono::steady_clock::now();

    t2_2.join();

    start_3 = std::chrono::steady_clock::now();
    vsumm_3.vector_summ(0, 50000);
    std::thread t2_3(&VSumm::vector_summ, &vsumm_3, 50001, 100000);
    end_3 = std::chrono::steady_clock::now();

    t2_3.join();

    start_4 = std::chrono::steady_clock::now();
    vsumm_4.vector_summ(0, 500000);
    std::thread t2_4(&VSumm::vector_summ, &vsumm_4, 500001, 1000000);
    end_4 = std::chrono::steady_clock::now();

    t2_4.join();

    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "2 потока \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;

    //4 ПОТОКА----------------------------------------------------------------

    start_1 = std::chrono::steady_clock::now();
    vsumm_1.vector_summ(0, 250);
    std::thread t4_1_1(&VSumm::vector_summ, &vsumm_1, 251, 500);
    std::thread t4_1_2(&VSumm::vector_summ, &vsumm_1, 501, 750);
    std::thread t4_1_3(&VSumm::vector_summ, &vsumm_1, 751, 1000);
    end_1 = std::chrono::steady_clock::now();

    t4_1_1.join();
    t4_1_2.join();
    t4_1_3.join();

    start_2 = std::chrono::steady_clock::now();
    vsumm_2.vector_summ(0, 2500);
    std::thread t4_2_1(&VSumm::vector_summ, &vsumm_2, 2501, 5000);
    std::thread t4_2_2(&VSumm::vector_summ, &vsumm_2, 5001, 7500);
    std::thread t4_2_3(&VSumm::vector_summ, &vsumm_2, 7501, 10000);
    end_2 = std::chrono::steady_clock::now();

    t4_2_1.join();
    t4_2_2.join();
    t4_2_3.join();

    start_3 = std::chrono::steady_clock::now();
    vsumm_3.vector_summ(0, 25000);
    std::thread t4_3_1(&VSumm::vector_summ, &vsumm_3, 25001, 50000);
    std::thread t4_3_2(&VSumm::vector_summ, &vsumm_3, 50001, 75000);
    std::thread t4_3_3(&VSumm::vector_summ, &vsumm_3, 75001, 100000);
    end_3 = std::chrono::steady_clock::now();

    t4_3_1.join();
    t4_3_2.join();
    t4_3_3.join();

    start_4 = std::chrono::steady_clock::now();
    vsumm_4.vector_summ(0, 250000);
    std::thread t4_4_1(&VSumm::vector_summ, &vsumm_4, 250001, 500000);
    std::thread t4_4_2(&VSumm::vector_summ, &vsumm_4, 500001, 750000);
    std::thread t4_4_3(&VSumm::vector_summ, &vsumm_4, 750001, 1000000);
    end_4 = std::chrono::steady_clock::now();

    t4_4_1.join();
    t4_4_2.join();
    t4_4_3.join();

    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "4 потока \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;
    
    //8 ПОТОКОВ----------------------------------------------------------------
    
    start_1 = std::chrono::steady_clock::now();
    vsumm_1.vector_summ(0, 125);
    std::thread t8_1_1(&VSumm::vector_summ, &vsumm_1, 126, 250);
    std::thread t8_1_2(&VSumm::vector_summ, &vsumm_1, 251, 375);
    std::thread t8_1_3(&VSumm::vector_summ, &vsumm_1, 376, 500);
    std::thread t8_1_4(&VSumm::vector_summ, &vsumm_1, 501, 625);
    std::thread t8_1_5(&VSumm::vector_summ, &vsumm_1, 626, 750);
    std::thread t8_1_6(&VSumm::vector_summ, &vsumm_1, 751, 875);
    std::thread t8_1_7(&VSumm::vector_summ, &vsumm_1, 876, 1000);
    end_1 = std::chrono::steady_clock::now();

    t8_1_1.join();
    t8_1_2.join();
    t8_1_3.join();
    t8_1_4.join();
    t8_1_5.join();
    t8_1_6.join();
    t8_1_7.join();

    start_2 = std::chrono::steady_clock::now();
    vsumm_2.vector_summ(0, 1250);
    std::thread t8_2_1(&VSumm::vector_summ, &vsumm_2, 1251, 2500);
    std::thread t8_2_2(&VSumm::vector_summ, &vsumm_2, 2501, 3750);
    std::thread t8_2_3(&VSumm::vector_summ, &vsumm_2, 3751, 5000);
    std::thread t8_2_4(&VSumm::vector_summ, &vsumm_2, 5001, 6250);
    std::thread t8_2_5(&VSumm::vector_summ, &vsumm_2, 6251, 7500);
    std::thread t8_2_6(&VSumm::vector_summ, &vsumm_2, 7501, 8750);
    std::thread t8_2_7(&VSumm::vector_summ, &vsumm_2, 8751, 10000);
    end_2 = std::chrono::steady_clock::now();

    t8_2_1.join();
    t8_2_2.join();
    t8_2_3.join();
    t8_2_4.join();
    t8_2_5.join();
    t8_2_6.join();
    t8_2_7.join();

    start_3 = std::chrono::steady_clock::now();
    vsumm_3.vector_summ(0, 12500);
    std::thread t8_3_1(&VSumm::vector_summ, &vsumm_3, 12501, 25000);
    std::thread t8_3_2(&VSumm::vector_summ, &vsumm_3, 25001, 37500);
    std::thread t8_3_3(&VSumm::vector_summ, &vsumm_3, 37501, 50000);
    std::thread t8_3_4(&VSumm::vector_summ, &vsumm_3, 50001, 62500);
    std::thread t8_3_5(&VSumm::vector_summ, &vsumm_3, 62501, 75000);
    std::thread t8_3_6(&VSumm::vector_summ, &vsumm_3, 75001, 87500);
    std::thread t8_3_7(&VSumm::vector_summ, &vsumm_3, 87501, 100000);
    end_3 = std::chrono::steady_clock::now();

    t8_3_1.join();
    t8_3_2.join();
    t8_3_3.join();
    t8_3_4.join();
    t8_3_5.join();
    t8_3_6.join();
    t8_3_7.join();

    start_4 = std::chrono::steady_clock::now();
    vsumm_4.vector_summ(0, 125000);
    std::thread t8_4_1(&VSumm::vector_summ, &vsumm_4, 125001, 250000);
    std::thread t8_4_2(&VSumm::vector_summ, &vsumm_4, 250001, 375000);
    std::thread t8_4_3(&VSumm::vector_summ, &vsumm_4, 375001, 500000);
    std::thread t8_4_4(&VSumm::vector_summ, &vsumm_4, 500001, 625000);
    std::thread t8_4_5(&VSumm::vector_summ, &vsumm_4, 625001, 750000);
    std::thread t8_4_6(&VSumm::vector_summ, &vsumm_4, 750001, 875000);
    std::thread t8_4_7(&VSumm::vector_summ, &vsumm_4, 875001, 1000000);
    end_4 = std::chrono::steady_clock::now();

    t8_4_1.join();
    t8_4_2.join();
    t8_4_3.join();
    t8_4_4.join();
    t8_4_5.join();
    t8_4_6.join();
    t8_4_7.join();

    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "8 потоков\t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;
    
    //16 ПОТОКОВ----------------------------------------------------------------

    start_1 = std::chrono::steady_clock::now();
    vsumm_1.vector_summ(0, 62);
    std::thread t16_1_1(&VSumm::vector_summ, &vsumm_1, 63, 125);
    std::thread t16_1_2(&VSumm::vector_summ, &vsumm_1, 126, 187);
    std::thread t16_1_3(&VSumm::vector_summ, &vsumm_1, 188, 250);
    std::thread t16_1_4(&VSumm::vector_summ, &vsumm_1, 251, 312);
    std::thread t16_1_5(&VSumm::vector_summ, &vsumm_1, 313, 375);
    std::thread t16_1_6(&VSumm::vector_summ, &vsumm_1, 376, 437);
    std::thread t16_1_7(&VSumm::vector_summ, &vsumm_1, 438, 500);
    std::thread t16_1_8(&VSumm::vector_summ, &vsumm_1, 501, 562);
    std::thread t16_1_9(&VSumm::vector_summ, &vsumm_1, 563, 625);
    std::thread t16_1_10(&VSumm::vector_summ, &vsumm_1, 626, 687);
    std::thread t16_1_11(&VSumm::vector_summ, &vsumm_1, 688, 750);
    std::thread t16_1_12(&VSumm::vector_summ, &vsumm_1, 751, 812);
    std::thread t16_1_13(&VSumm::vector_summ, &vsumm_1, 813, 875);
    std::thread t16_1_14(&VSumm::vector_summ, &vsumm_1, 876, 937);
    std::thread t16_1_15(&VSumm::vector_summ, &vsumm_1, 938, 1000);
    end_1 = std::chrono::steady_clock::now();

    t16_1_1.join();
    t16_1_2.join();
    t16_1_3.join();
    t16_1_4.join();
    t16_1_5.join();
    t16_1_6.join();
    t16_1_7.join();
    t16_1_8.join();
    t16_1_9.join();
    t16_1_10.join();
    t16_1_11.join();
    t16_1_12.join();
    t16_1_13.join();
    t16_1_14.join();
    t16_1_15.join();

    start_2 = std::chrono::steady_clock::now();
    vsumm_2.vector_summ(0, 620);
    std::thread t16_2_1(&VSumm::vector_summ, &vsumm_2, 621, 1250);
    std::thread t16_2_2(&VSumm::vector_summ, &vsumm_2, 1251, 1870);
    std::thread t16_2_3(&VSumm::vector_summ, &vsumm_2, 1871, 2500);
    std::thread t16_2_4(&VSumm::vector_summ, &vsumm_2, 2501, 3120);
    std::thread t16_2_5(&VSumm::vector_summ, &vsumm_2, 3121, 3750);
    std::thread t16_2_6(&VSumm::vector_summ, &vsumm_2, 3751, 4370);
    std::thread t16_2_7(&VSumm::vector_summ, &vsumm_2, 4371, 5000);
    std::thread t16_2_8(&VSumm::vector_summ, &vsumm_2, 5001, 5620);
    std::thread t16_2_9(&VSumm::vector_summ, &vsumm_2, 5621, 6250);
    std::thread t16_2_10(&VSumm::vector_summ, &vsumm_2, 6251, 6870);
    std::thread t16_2_11(&VSumm::vector_summ, &vsumm_2, 6871, 7500);
    std::thread t16_2_12(&VSumm::vector_summ, &vsumm_2, 7501, 8120);
    std::thread t16_2_13(&VSumm::vector_summ, &vsumm_2, 8121, 8750);
    std::thread t16_2_14(&VSumm::vector_summ, &vsumm_2, 8751, 9370);
    std::thread t16_2_15(&VSumm::vector_summ, &vsumm_2, 9371, 10000);
    end_2 = std::chrono::steady_clock::now();

    t16_2_1.join();
    t16_2_2.join();
    t16_2_3.join();
    t16_2_4.join();
    t16_2_5.join();
    t16_2_6.join();
    t16_2_7.join();
    t16_2_8.join();
    t16_2_9.join();
    t16_2_10.join();
    t16_2_11.join();
    t16_2_12.join();
    t16_2_13.join();
    t16_2_14.join();
    t16_2_15.join();

    start_3 = std::chrono::steady_clock::now();
    vsumm_3.vector_summ(0, 6200);
    std::thread t16_3_1(&VSumm::vector_summ, &vsumm_3, 6201, 12500);
    std::thread t16_3_2(&VSumm::vector_summ, &vsumm_3, 12501, 18700);
    std::thread t16_3_3(&VSumm::vector_summ, &vsumm_3, 18701, 25000);
    std::thread t16_3_4(&VSumm::vector_summ, &vsumm_3, 25001, 31200);
    std::thread t16_3_5(&VSumm::vector_summ, &vsumm_3, 31201, 37500);
    std::thread t16_3_6(&VSumm::vector_summ, &vsumm_3, 37501, 43700);
    std::thread t16_3_7(&VSumm::vector_summ, &vsumm_3, 43701, 50000);
    std::thread t16_3_8(&VSumm::vector_summ, &vsumm_3, 50001, 56200);
    std::thread t16_3_9(&VSumm::vector_summ, &vsumm_3, 56201, 62500);
    std::thread t16_3_10(&VSumm::vector_summ, &vsumm_3, 62501, 68700);
    std::thread t16_3_11(&VSumm::vector_summ, &vsumm_3, 68701, 75000);
    std::thread t16_3_12(&VSumm::vector_summ, &vsumm_3, 75001, 81200);
    std::thread t16_3_13(&VSumm::vector_summ, &vsumm_3, 81201, 87500);
    std::thread t16_3_14(&VSumm::vector_summ, &vsumm_3, 87501, 93700);
    std::thread t16_3_15(&VSumm::vector_summ, &vsumm_3, 93701, 100000);
    end_3 = std::chrono::steady_clock::now();

    t16_3_1.join();
    t16_3_2.join();
    t16_3_3.join();
    t16_3_4.join();
    t16_3_5.join();
    t16_3_6.join();
    t16_3_7.join();
    t16_3_8.join();
    t16_3_9.join();
    t16_3_10.join();
    t16_3_11.join();
    t16_3_12.join();
    t16_3_13.join();
    t16_3_14.join();
    t16_3_15.join();
    
    start_4 = std::chrono::steady_clock::now();
    vsumm_4.vector_summ(0, 62000);
    std::thread t16_4_1(&VSumm::vector_summ, &vsumm_4, 62001, 125000);
    std::thread t16_4_2(&VSumm::vector_summ, &vsumm_4, 125001, 187000);
    std::thread t16_4_3(&VSumm::vector_summ, &vsumm_4, 187001, 250000);
    std::thread t16_4_4(&VSumm::vector_summ, &vsumm_4, 250001, 312000);
    std::thread t16_4_5(&VSumm::vector_summ, &vsumm_4, 312001, 375000);
    std::thread t16_4_6(&VSumm::vector_summ, &vsumm_4, 375001, 437000);
    std::thread t16_4_7(&VSumm::vector_summ, &vsumm_4, 437001, 500000);
    std::thread t16_4_8(&VSumm::vector_summ, &vsumm_4, 500001, 562000);
    std::thread t16_4_9(&VSumm::vector_summ, &vsumm_4, 562001, 625000);
    std::thread t16_4_10(&VSumm::vector_summ, &vsumm_4, 625001, 687000);
    std::thread t16_4_11(&VSumm::vector_summ, &vsumm_4, 687001, 750000);
    std::thread t16_4_12(&VSumm::vector_summ, &vsumm_4, 750001, 812000);
    std::thread t16_4_13(&VSumm::vector_summ, &vsumm_4, 812001, 875000);
    std::thread t16_4_14(&VSumm::vector_summ, &vsumm_4, 875001, 937000);
    std::thread t16_4_15(&VSumm::vector_summ, &vsumm_4, 937001, 1000000);
    end_4 = std::chrono::steady_clock::now();

    t16_4_1.join();
    t16_4_2.join();
    t16_4_3.join();
    t16_4_4.join();
    t16_4_5.join();
    t16_4_6.join();
    t16_4_7.join();
    t16_4_8.join();
    t16_4_9.join();
    t16_4_10.join();
    t16_4_11.join();
    t16_4_12.join();
    t16_4_13.join();
    t16_4_14.join();
    t16_4_15.join();
    
    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "16 потоков\t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;
    
    return 0;
}