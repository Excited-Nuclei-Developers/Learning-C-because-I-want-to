# include <iostream>
# include <cmath>
using namespace std;

void inputData(double arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void sortArray(double arr[], int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

double calculateSum(double arr[], int n){
    double tmp=0;
    for (int i = 0; i < n; i++){
        tmp+=arr[i];
    }
    return tmp;
}

double calculateMean(double arr[], int n){
    return calculateSum(arr,n)/n;
}

double findMin(double arr[], int n){
    double min = arr[0];
    for (int i = 1; i < n; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

double findMax(double arr[], int n){
    double max = arr[0];
    for (int i = 1; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

double calculateMedian(double arr[], int n){
    double median;
    int mid;
    if (n%2==0){
        mid = (int) n/2;
        median = (arr[mid - 1] + arr[mid]) / 2;
    } else {
        mid = (int) n/2;
        median = arr[mid];
    }
    return median;
}

double calculateVariance(double arr[], int n, double mean){
    double var, sm_dev;
    sm_dev = 0.0 ;
    for (int i = 0; i < n; i++){
        double diff = (arr[i] - mean);
        sm_dev += diff*diff;
    }
    var = sm_dev/n;
    return var;
}

double calculateStdDev(double variance){
    double std_dev;
    std_dev = sqrt(variance);
    return std_dev;
}

int main(){
    const int MAX = 100;
    double arr[MAX];  // fixed array
    int n;

    cout << "Enter number of elements: ";
    cin >> n;
    // double arr[n]; // can be used too but only works for GCC / Clang (as an extension)

    if (n > MAX) {
        cout<<"Max limit for entry is "<<MAX<<endl;
    }else{
    inputData(arr,n);
    cout<<"\nInput Array Of Numbers: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<", ";
    };
    sortArray(arr,n);
    cout<<endl;
    cout<<"Sorted Array Of Numbers: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<", ";
    };
    cout<<endl;
    double var, sum, mean, min, max, median, std_dev, range;
    sum = calculateSum(arr, n);
    mean = calculateMean(arr, n);
    min = findMin(arr, n);
    max = findMax(arr, n);
    range = max - min ;
    median = calculateMedian(arr, n);
    var = calculateVariance(arr, n, mean);
    std_dev = calculateStdDev(var);
    cout << "\nStatistics:\n"
     << "-----------------------\n"
     << "Sum:                 " << sum << "\n"
     << "Min:                 " << min << "\n"
     << "Max:                 " << max << "\n"
     << "Mean:                " << mean << "\n"
     << "Median:              " << median << "\n"
     << "Range:               " << range << "\n"
     << "Variance:            " << var << "\n"
     << "Standard deviation:  " << std_dev << "\n";
    return 0;
    };
}