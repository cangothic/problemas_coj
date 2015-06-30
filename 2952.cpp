/*http://coj.uci.cu/24h/problem.xhtml?pid=2952
Tobby and Tanks I*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> tanks;
template<class T>
T binarySearch(T element,vector<T> _array,T left,T right){
    if(left==right)return (_array[right]<=element)? right:right-1;
    T center=(left+right)/2;
    if(element<=_array[center]) return binarySearch(element,_array,left,center);
    else return binarySearch(element,_array,center+1,right);
}
int n,q;
int main(){
    int w,k;
    while(scanf("%d%d",&n,&q)!=EOF){
        tanks.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&w);
            tanks.push_back(w);
        }
        tanks[0]=1;
        for(int i=1;i<n;i++){
            tanks[i]+=tanks[i-1];
        }
        for(int i=0;i<q;i++){
            scanf("%d",&k);
            if(i==q-1){
                printf("%d\n",binarySearch(k,tanks,0,(int)tanks.size()-1)+1);
            }
            else printf("%d ",binarySearch(k,tanks,0,(int)tanks.size()-1)+1);
        }

    }
}
