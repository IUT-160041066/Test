#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){

    for(int x=1;;x++){
         int n;
        scanf("%d",&n);
        if(n==0)
            break;
       /* int ar[10005][10005];
        memset(ar,0,sizeof(ar));*/
        vector<int>num;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            num.push_back(a);
        }
        vector<int>result;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                result.push_back(num[i]+num[j]);
            }
        }
        sort(result.begin(),result.end());
        int m;
        scanf("%d",&m);
      /* for(int o=0;o<result.size();o++){
            cout<<result[o] <<endl;
        }*/
        vector<int>query;
        for(int i=0;i<m;i++){
            int z;
            cin>>z;
            query.push_back(z);
        }
        //for(int o=0;o<query.size();o++){
            //cout<< query[o] << endl;
       // }
        printf("Case %d:\n",x);
        for(int i=0;i<m;i++){
        int res;
        int flag=0;

         int b=0;
        int e=result.size()-1;
        while(b<=e){

            //cout<< "b=" <<b << " e="<<e<<endl;
            int mid=(b+e)/2;
           /* if(b-e==1 || e-b==1){
                for(int j=b-1;j<=e+1;j++)
                    check.push_back(result[j]);
            }*/
            res=mid;
            if(result[mid]==query[i]){
                flag=1;
                res=result[mid];
                break;
            }
            else if(query[i]>result[mid])
                b=mid+1;
            else if(query[i]<result[mid])
                e=mid-1;

        }
       if(flag==0){
            vector<int>check;
           int st;
           int en;
           if(!(res-1>=0))
            st=res;
           else
            st=res-1;
           if(!(res+1<result.size()))
            en=res;
            else
                en=res+1;
            res=result[st];
            for(int p=st;p<=en;p++){
               if(abs(result[p]-query[i]) < abs(res-query[i]))
                res=result[p];
            }
        }
        printf("Closest sum to %d is %d.\n",query[i],res);
        }

    }
}
