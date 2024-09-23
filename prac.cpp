#include <iostream>
#include<vector>
using namespace std;
#define max_day 7
#define max_projects 5
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
}
int main()
{
    vector<int> p ={200, 150, 100, 50, 300};
    vector<int> d ={3, 2, 1, 2, 5};
    findProjects(p,d);
    return 0;
}
