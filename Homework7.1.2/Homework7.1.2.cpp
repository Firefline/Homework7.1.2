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
        }
    }
    void vector_summ()
    {
        for (int i = 0; i <= elements_num; ++i)
        {
            v_summ.push_back(v_1[i] + v_2[i]);
        }
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

    auto start_1 = std::chrono::steady_clock::now();
    vsumm_1.vector_summ();
    auto end_1 = std::chrono::steady_clock::now();

    auto start_2 = std::chrono::steady_clock::now();
    vsumm_2.vector_summ();
    auto end_2 = std::chrono::steady_clock::now();

    auto start_3 = std::chrono::steady_clock::now();
    vsumm_3.vector_summ();
    auto end_3 = std::chrono::steady_clock::now();

    auto start_4 = std::chrono::steady_clock::now();
    vsumm_4.vector_summ();
    auto end_4 = std::chrono::steady_clock::now();

    std::cout << "Количество аппаратных ядер: " << n << std::endl;
    std::cout << std::endl;
    std::chrono::duration<double> elapsed_seconds_1 = end_1 - start_1;
    std::chrono::duration<double> elapsed_seconds_2 = end_2 - start_2;
    std::chrono::duration<double> elapsed_seconds_3 = end_3 - start_3;
    std::chrono::duration<double> elapsed_seconds_4 = end_4 - start_4;
    std::cout << "\t\t" << "1000\t\t" << "10000\t\t" << "100000\t\t" << "1000000" << std::endl;
    std::cout << "1 поток  \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;

    start_1 = std::chrono::steady_clock::now();
    std::thread t2_1(&VSumm::vector_summ, &vsumm_1);
    end_1 = std::chrono::steady_clock::now();
    start_2 = std::chrono::steady_clock::now();
    std::thread t2_2(&VSumm::vector_summ, &vsumm_2);
    end_2 = std::chrono::steady_clock::now();
    start_3 = std::chrono::steady_clock::now();
    std::thread t2_3(&VSumm::vector_summ, &vsumm_3);
    end_3 = std::chrono::steady_clock::now();
    start_4 = std::chrono::steady_clock::now();
    std::thread t2_4(&VSumm::vector_summ, &vsumm_4);
    end_4 = std::chrono::steady_clock::now();
    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "2 потока \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;
    t2_1.join();
    t2_2.join();
    t2_3.join();
    t2_4.join();

    start_1 = std::chrono::steady_clock::now();
    std::thread t3_1(&VSumm::vector_summ, &vsumm_1);
    end_1 = std::chrono::steady_clock::now();
    start_2 = std::chrono::steady_clock::now();
    std::thread t3_2(&VSumm::vector_summ, &vsumm_2);
    end_2 = std::chrono::steady_clock::now();
    start_3 = std::chrono::steady_clock::now();
    std::thread t3_3(&VSumm::vector_summ, &vsumm_3);
    end_3 = std::chrono::steady_clock::now();
    start_4 = std::chrono::steady_clock::now();
    std::thread t3_4(&VSumm::vector_summ, &vsumm_4);
    end_4 = std::chrono::steady_clock::now();
    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "3 потока \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;
    t3_1.join();
    t3_2.join();
    t3_3.join();
    t3_4.join();

    start_1 = std::chrono::steady_clock::now();
    std::thread t4_1(&VSumm::vector_summ, &vsumm_1);
    end_1 = std::chrono::steady_clock::now();
    start_2 = std::chrono::steady_clock::now();
    std::thread t4_2(&VSumm::vector_summ, &vsumm_2);
    end_2 = std::chrono::steady_clock::now();
    start_3 = std::chrono::steady_clock::now();
    std::thread t4_3(&VSumm::vector_summ, &vsumm_3);
    end_3 = std::chrono::steady_clock::now();
    start_4 = std::chrono::steady_clock::now();
    std::thread t4_4(&VSumm::vector_summ, &vsumm_4);
    end_4 = std::chrono::steady_clock::now();
    elapsed_seconds_1 = end_1 - start_1;
    elapsed_seconds_2 = end_2 - start_2;
    elapsed_seconds_3 = end_3 - start_3;
    elapsed_seconds_4 = end_4 - start_4;
    std::cout << "4 потока \t" << elapsed_seconds_1.count() << "s\t" << elapsed_seconds_2.count() << "s\t" << elapsed_seconds_3.count() << "s\t" << elapsed_seconds_4.count() << "s" << std::endl;
    t4_1.join();
    t4_2.join();
    t4_3.join();
    t4_4.join();

    return 0;
}