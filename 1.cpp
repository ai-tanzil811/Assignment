// Ashraful Islam Tanzil 0112230028
#include <iostream>
#include <vector>
#include <algorithm>
#define max_day 7
#define max_projects 5
using namespace std;
//------------------------------------->ANS TO THE QUESTION 1<------------------------------

void merge(int array[], int mid, int l, int r)
{
    int t1 = mid - l + 1;
    int t2 = r - mid;
    int le[t1];
    int ri[t2];
    for (int i = 0; i < t1; i++)
    {
        le[i] = array[l + i];
    }
    for (int i = 0; i < t2; i++)
    {
        ri[i] = array[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < t1 && j < t2)
    {
        if (le[i] > ri[i])
        {
            array[k] = le[i];
            i++;
        }
        else
        {
            array[k] = ri[j];
            j++;
        }
        k++;
    }
    while (i < t1)
    {
        array[k] = le[i];
        i++;
        k++;
    }
    while (j < t2)
    {
        array[k] = ri[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int left, int right)
{
    int mid = (left + right) / 2;
    if (left < right)
    {
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, mid, left, right);
    }
}
void findKthLargest(int array[], int n, int k)
{
    mergeSort(array, 0, n - 1);
    cout << endl
         << array[k - 1];
}
//---------------------------------------------< ANS TO THE QUESTION 2>----------------------------------
struct item
{
    int idx;
    double weight, value, unitPrice;
    item(int idx, double w, double v) : idx(idx), weight(w), value(v), unitPrice(v / w) {}
    void display(double w)
    {
        cout << "item " << idx << " (" << w << " kg)";
    }
};
void Pilferage(vector<item> items, int capacty)
{
    sort(items.begin(), items.end(), [](item a, item b)
         { return a.unitPrice > b.unitPrice; });
    int thief = 1;
    double temp = capacty;
    for (int i=0;items.size();i++)
    {

        while (items[i].weight>0)
        {
            cout << "Theif " << thief << " : ";
            if (items[i].weight <= temp)
            {
                items[i].display(items[i].weight);
                temp = temp - items[i].weight;
                items[i].weight = 0;
            }
            else
            {
                items[i].display(temp);
                items[i].weight = items[i].weight - temp;
                temp = 0;
            }
            if (temp == 0)
            {
                thief++;
                temp = capacty;
                cout << endl;
            }
            else
                cout << ",";
        }
    }
}
//---------------------------------------------< ANS TO THE QUESTION 3>----------------------------------
void rodcutting(const vector<int>&p,int n)
{
   
 vector<int> temp(n+1,0);
 vector<int>temp2(n+1,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(temp[i] <p[j]+temp[i-j-1]){
                temp[i] = p[j]+temp[i-j-1];
                temp2[i] =j+1;
            }
        }
    }
    cout<<"max rev "<<temp[n]<<endl;

    cout<<"Backtrace"<<endl;
    int l = n;
    while (l > 0) {
        cout << "Cut len : " << temp2[l] << endl;
        l -= temp2[l];
    }

}
//---------------------------------------------< ANS TO THE QUESTION 4>----------------------------------
void findProjects(vector<int>p,vector<int>d)
{
vector<int> t1(max_day+1,0);
vector<int> t2(max_day+1,0);
for(int i=0;i<p.size();i++)
{
    for(int j=max_day;j>=d[i];j--)
    {
        if(t1[j]<t1[j-d[i]]+p[i])
        {
            t1[j]=(t1[j-d[i]]+p[i]);
            t2[j]=i;

        }
    }
}
cout<<"max profit : "<<t1[max_day]<<endl;
int td=max_day;
cout<<"projects: " <<endl;
//int (i=0;i<max_day)
while (td > 0) {
        if (t2[td] != 0 || (td == d[t2[td]] && t1[td] != 0)) {
            cout<<"proj ->"<< t2[td] + 1 << " "<<endl;
            td -= d[t2[td]];
        } else {
            break;
        }
}
}//---------------------------------------------< END >---------------------------------------------------