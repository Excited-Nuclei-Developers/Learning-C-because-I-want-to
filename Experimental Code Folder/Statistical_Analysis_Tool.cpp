# include <iostream>
# include <cmath>
using namespace std;

// taking input data from user
void inputData(double arr[], int n){
    for (int i = 0; i < n; i++){
        double number;
        cout << "Enter element " << i + 1 << ": ";
        cin >> number;
        arr[i] = number;
    }
}

// sorting the array (i/p data)
// [2,1,3,5,4] : takes 2 and 1 checks if 2 > 1 -> arr[0]<->arr[1] continues
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

// Adding all values
double calculateSum(double arr[], int n){
    double sum;
    for (int i = 0; i < n; i++){
        sum+=arr[i];
    }
    return sum;
}

// Mean calculation
double calculateMean(double arr[], int n){
    return calculateSum(arr, n)/n;
};

// minimum value 
double findMin(double arr[], int n){
    double min = arr[0];
    for (int i = 1; i < n; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

// maximum value
double findMax(double arr[], int n){
    double max = arr[0];
    for (int i = 1; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

// calculate median
double calculateMedian(double arr[], int n){
    int idx, idx1, idx2;
    if (n % 2 == 0){
        idx1 = (int) (n/2) - 1;
        idx2 = (int) (n/2);
        return (arr[idx1] + arr[idx2])/2;
    } else {
        idx = (int) n/2; // if n=5 then (int) n/2 >> 2
        return arr[idx];
    }
}

// calculate variance
double calculateVariance(double arr[], int n, double mean){
    double div;

    for (int i = 0; i < n; i++){
        // (sum of square of all (mean - element)/n)
        double diff = (mean - arr[i]);
        div += diff * diff;
    }
    return div/n;
}

// calculate standard deviatin
double calculateStdDev(double variance){
    return sqrt(variance);
}

int main(){
    int n;
    // main code
    cout << "Enter the Size of Array: ";
    cin >> n;
    double array[n];
    inputData(array, n);
    cout << "\nInput Array Of Numbers: ";
    for (int i = 0; i < n; i++){
        cout << array[i] << ", ";
    }
    sortArray(array, n);
    cout << "\nInput Array Of Numbers: ";
    for (int i = 0; i < n; i++){
        cout << array[i] << ", ";
    }
    cout << endl;
    double var, sum, mean, min, max, median, std_dev, range;
    
    sum = calculateSum(array, n);
    mean = calculateMean(array, n);
    min = findMin(array, n);
    max = findMax(array, n);
    median = calculateMedian(array, n);
    var = calculateVariance(array, n, mean);
    std_dev = calculateStdDev(var);

    cout << "\nStatistics:\n"
     << "-----------------------\n"
     << "Sum:                 " << sum << "\n"
     << "Minimum:             " << min << "\n"
     << "Maximum:             " << max << "\n"
     << "Mean:                " << mean << "\n"
     << "Median:              " << median << "\n"
     << "Range:               " << max - min << "\n"
     << "Variance:            " << var << "\n"
     << "Standard Deviation:  " << std_dev << "\n";
}