#include <iostream>
#include <sstream>
using namespace std;

void mergeSort(int *mas, int first, int last)
{
    if (first == last) return;
    int mid = (first + last) / 2;

    mergeSort(mas, first, mid);
    mergeSort(mas, mid + 1, last);

    int i = first;
    int j = mid + 1;
    int *tmp = new int [last] ;
    for (int step = 0; step < last - first + 1; step++)
    {
        if ((j > last) || ((i <= mid) && (mas[i] < mas[j])))
        {
            tmp[step] = mas[i];
            i++;
        }
        else
        {
            tmp[step] = mas[j];
            j++;
        }
    }
    for (int step = 0; step < last - first + 1; step++)
        mas[first + step] = tmp[step];
    delete [] tmp;
}

int main(){
    int length =0;

    string str;
    getline(cin,str);
    istringstream stream1(str);
    if(!(stream1>>length)){
        cout<<"An error has occuried while reading input data."<<endl;
        exit(0);
    }

    int *mas=new int [length];

    string mas_str;
    getline(cin,mas_str);
    istringstream stream (mas_str);
    for(int i=0;i<length;i++){
        if(!(stream>>mas[i])){
            cout<<"An error has occuried while reading input data."<<endl;
            delete [] mas;
            exit(0);
        }
    }

    mergeSort( mas,0,length-1);

    for(int i=0;i<length;i++){
        cout<<mas[i]<<" ";
    }
    cout<<endl;

    delete [] mas;
    return 0;
}