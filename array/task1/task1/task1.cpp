#include <iostream>
#include <vector>
using namespace std;

/*функция, которая находит 
минимальное число множества*/
float min(vector <float> arr) {
    float min = arr[0];
    for (int a = 1; a < arr.size(); a++) {
        if (arr[a] < min) {
            min = arr[a];
        }
    }
    return min;
}

/*функция, которая находит
наибольшее число множества*/
float max(vector <float> arr) {
    float max = arr[0];
    for (int b = 0; b < arr.size(); b++) {
        if (arr[b] > max) {
            max = arr[b];
        }
    }
    return max;
}

/*функция, которая меняет
наибольший и наименьший 
элементы множества */
vector <float> change(vector <float> arr) {
    int indMax = 0;
    int indMin = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[indMax])
            indMax = i;
        if (arr[i] < arr[indMin])
            indMin = i;
    }

    swap(arr[indMin], arr[indMax]);
    return arr;

}

/*функция находит количество
различных элементов, выводит 
числа и сколько раз каждое 
из них встречается (без повторов)*/
float difference(vector <float> arr) {
    int different = 0;
    for (int a = 0; a < arr.size(); a++) {
        bool stop = false;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[a] == arr[i] && i != a) {
                stop = true;
                break;
            }
        }
        if (!stop)
            different++;
    }
    for (int i = 0; i < arr.size(); i++) {
        bool alrCounted = false;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                alrCounted = true;
                break;
            }
        }
        if (alrCounted)
            continue;
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] == arr[i])
                count++;
        }
        cout << "Число " << arr[i] <<
            " встречается " << count
            << " раз" << endl;
    }
    return different;
}

int main()
{
    setlocale(LC_ALL, "ru");
    vector <float> arr;
    float num;
    int amount;
    cout << "Сколько чисел "
        << "вы хотите ввести ? " << endl;
    cin >> amount;
    cout << "Введите числа:  " << endl;
    int i = 0;
    while (i <= amount){//заполнение массива
        cin >> num;
        arr.push_back(num);
        i++;
        if (i == amount)
            break;
    }

    float minimum = min(arr); //задание 1
    cout << "Минимальный элемент: "
        << minimum << endl;
    float maximum = max(arr);
    cout << "Максимальный элемент: "
        << maximum << endl;
    
    vector <float> newArr = change(arr);
    cout << "Новый массив: " << endl;//задание 2
    for (float i : newArr) {
        cout << i << " ";
    } cout << endl;
    
    cout << "Количество разлиных " <<//задание 3
        "элементов массива: " 
        << difference(arr)
        << endl;
}
