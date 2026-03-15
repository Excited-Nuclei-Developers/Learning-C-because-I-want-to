#include <iostream>
using namespace std;

const int MAX = 10;

void inputMatrix(int A[MAX][MAX], int r, int c, char name){
    cout << "Enter elements of Matrix " << name << ":\n";
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << "Enter element [" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }
}

void displayMatrix(int A[MAX][MAX], int r, int c){
    cout << "Result Matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r, int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r, int c){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            C[i][j] = A[i][j] - B[i][j];
}

// a[i1][j1] @ b[i2][j2] >> j1==i2 ->R[i1][j2]
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            C[i][j] = 0;
            for(int k=0;k<c1;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int determinant2x2(int A[MAX][MAX]){
    return (A[0][0]*A[1][1]) - (A[0][1]*A[1][0]);
}

int main(){

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1,c1,r2,c2,choice;

    cout<<"------ Matrix Operations ------\n";
    cout<<"1. Add Matrices\n";
    cout<<"2. Subtract Matrices\n";
    cout<<"3. Multiply Matrices\n";
    cout<<"4. Determinant (2x2)\n";

    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==4){

        cout<<"Enter elements for a 2x2 matrix\n";

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<"Enter element ["<<i<<"]["<<j<<"] : ";
                cin>>A[i][j];
            }
        }

        cout<<"Determinant = "<<determinant2x2(A)<<endl;
        return 0;
    }

    cout<<"Enter rows for Matrix A: ";
    cin>>r1;

    cout<<"Enter columns for Matrix A: ";
    cin>>c1;

    cout<<"Enter rows for Matrix B: ";
    cin>>r2;

    cout<<"Enter columns for Matrix B: ";
    cin>>c2;

    inputMatrix(A,r1,c1,'A');
    inputMatrix(B,r2,c2,'B');

    if(choice==1 && r1==r2 && c1==c2){
        add(A,B,C,r1,c1);
        displayMatrix(C,r1,c1);
    }
    else if(choice==2 && r1==r2 && c1==c2){
        subtract(A,B,C,r1,c1);
        displayMatrix(C,r1,c1);
    }
    else if(choice==3 && c1==r2){
        multiply(A,B,C,r1,c1,c2);
        displayMatrix(C,r1,c2);
    }
    else{
        cout<<"Invalid matrix size for selected operation!\n";
    }

    return 0;
}