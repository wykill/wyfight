#include <iostream>
#include <ctime>
#define MAX 10

// 冒泡排序 
// Sort 20000 nums, The run time is: 1.35316s
// Sort 100000 nums, The run time is: 34.7464s

// 选择排序
// Sort 20000 nums, The run time is: 0.343353s
// Sort 100000 nums, The run time is: 8.87131s

// 插入排序
// Sort 20000 nums, The run time is: 0.221429s
// Sort 100000 nums, The run time is: 5.37307s

// 希尔排序     分组 插入排序！！！
// Sort 20000 nums, The run time is: 0.0045s
// Sort 100000 nums, The run time is: 0.023168s
// Sort 1000000 nums, The run time is: 0.293585s
// Sort 2000000 nums, The run time is: 0.665805s

// 快速排序     分治思想！！！ 确定一个flagNum，小的放左边，大的放右边
// Sort 20000 nums, The run time is: 0.002432s
// Sort 100000 nums, The run time is: 0.016579s
// Sort 1000000 nums, The run time is: 0.164764s
// Sort 2000000 nums, The run time is: 0.344868s

void printExecutedTime(clock_t start, clock_t end, long num)
{
    ::std::cout << "Sort " << num << " nums, The run time is: " <<(double)(end - start) / CLOCKS_PER_SEC << "s" << ::std::endl;
}

void buildRandomArr(int* arr, int length)
{
    srand((int)time(0));

    for (int i = 0; i < length; i++) {
        arr[i] = rand() % MAX;
    }
}

void printArr(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        ::std::cout << arr[i] << " ";
        if (i >= 20) {
            ::std::cout << "...";
            break;
        }
    }
    ::std::cout << ::std::endl;
}

void swap(int* arr, int pos1, int pos2) 
{
    int tmp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = tmp;
}

void bubbleSort(int* arr, int length) 
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

void selectSort(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        int minNum = arr[i];
        int minPos = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < minNum) {
                minNum = arr[j];
                minPos = j;
            }
        }
        if (i != minPos) {
            swap(arr, i, minPos);
        }
    }
}

void insertSort(int* arr, int length) 
{
    for (int i = 1; i < length; i++) {
        int tmp = arr[i];
        int j;
        bool moveFlag = false;
        for (j = i - 1; j >= 0; j--) {
            if (tmp < arr[j]) {
                arr[j + 1] = arr[j];
                moveFlag = true;
            } else {
                break;
            }
        }
        if (moveFlag) {
            arr[j + 1] = tmp;
        }
    }
}

void shellSort(int* arr, int length)          // 希尔排序其实就是分组的插入排序，注意分组数  按 除以3 + 1 来算最为效率高
{
    int step = length;
    do {
        step = step / 3 + 1;         // 分组步长
        for (int index = 0; index < step; index++) {
            for (int i = index + step; i < length; i += step) {
                int tmp = arr[i];
                int j;
                for (j = i - step; j >= 0; j -= step) {
                    if (arr[j] <= tmp) {
                        break;
                    }
                    arr[j + step] = arr[j]; 
                }
                arr[j + step] = tmp; 
            }
        }
    } while (step != 1);
}

void quickSort(int* arr, int start, int end)           // 分治思想，大问题拆分成小问题
{
    int left = start;
    int right = end;
    int flagNum = arr[left];
    if (left >= right) {
        return;
    }
    while (left < right) {
        while (left < right && arr[right] >= flagNum) {
            right--;
        }
        if (arr[right] < flagNum) {
            arr[left] = arr[right];
        }

        while (left < right && arr[left] <= flagNum) {
            left++;
        }
        if (arr[left] > flagNum) {
            arr[right] = arr[left];
        }
    }
    arr[left] = flagNum;
    quickSort(arr, start, left - 1);
    quickSort(arr, left + 1, end);
}

int main()
{
    clock_t startT, endT;
    int arr[MAX];
    buildRandomArr(arr, MAX);

    ::std::cout << "========Original Arr=======" << ::std::endl;
    printArr(arr, MAX);
    startT = clock();

    // ::std::cout << "=======Sort Begin=========" << ::std::endl;
    // bubbleSort(arr, MAX);
    // selectSort(arr, MAX);
    // insertSort(arr, MAX);
    // shellSort(arr, MAX);
    quickSort(arr, 0, MAX - 1);
    // ::std::cout << "=======Sort End=========" << ::std::endl;
    endT = clock();

    ::std::cout << "========Sorted Arr=======" << ::std::endl;
    printArr(arr, MAX);
    ::std::cout << "========Cost Time=======" << ::std::endl;
    printExecutedTime(startT, endT, MAX);
    
    return 0;
}