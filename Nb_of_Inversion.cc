#include <cmath>
#include <iostream>
#include <vector>
#define INIF 1000000

class Kata
{
public:
    int countInversions(std::vector<int> array)
    {
      int count = 0;
      for(int i = 0; i<array.size(); i++)
        for(int j = i; j<array.size(); j++)
          count += array[i]>array[j]?1:0;
      return count;
    }
};



void MERGE(int *A, int p, int q, int r, int &nb){
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for(int i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    L[n1] = INIF;

    for(int i = 0; i < n2; i++){
        R[i] = A[q + i + 1];
    }
    R[n2] = INIF;

    int i = 0;
    int j = 0;
    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }
        else{
            A[k] = R[j];
            nb = nb + (n1 - i);
            j += 1;
        }
    }
    //return nb;
}

void MERGE_COUNT(int *A, int p, int r, int &nb){

    if(p < r){
        int q = std::floor((p + r) / 2.0);
        MERGE_COUNT(A, p, q, nb);
        MERGE_COUNT(A, q + 1, r, nb);
        MERGE(A, p, q, r, nb);
    }
}

int main(){
    Kata kata;
    int m = kata.countInversions(std::vector<int> {6, 5, 4, 3, 3, 3, 3, 2, 1});
    std::cout << m << "\n";
//
//    std::cout << std::floor(3.1) << std::endl;
//    std::cout << 5 / 2 << "\n";

   // int A[8] = {15, -12, -16, -10, 34, -6, 33, -1};
    int A[9] = {6, 5, 4, 3, 3, 3, 3, 2, 1};
    //int A[6] = {6, 5, 4, 3, 2, 1};
    //int A[5] = {1, 20, 6, 4, 5};
    //int A[] = {-7, -19, 1, 10, 24, -4, 19, 33, -10, -10, 5, -29, -5, -7, -21, -15};
    //int A[12] = {-9, 27, -26, 34, -14, 30, 2, -11, 9, 0, 24, 8};
    //int A[6] = {6, 5, 2, 3, 4, 1};

    int nb = 0;
    MERGE_COUNT(A, 0, 8, nb);
    std:: cout << nb << "\n";
    for(int i = 0; i < 9; i++){
        std::cout << A[i] << ", ";

    }
    std::cout << "\n";

//    int nb2 = 0;
//    for(int i = 0; i < 5; i++){
//        for(int j = i + 1; j < 6; j++){
//            if(A[i] > A[j]){
//                std::cout << A[i] << ", " << A[j] << "\n";
//                nb2 += 1;
//            }
//        }
//        //std::cout << "\n";
//    }
//    std::cout << "\n";
//    std::cout << nb2 << "\n";
}