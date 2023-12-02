// voting 
#include <iostream>
using namespace std;

int main() {
     int votecount;
     int ballot[6] = {0};
     
     cout<<"Enter the votecount:"<<endl;
     cin>>votecount;
     while (votecount > 0){
          int vote;
          cout<<"Enter the vote :"<<endl;
          cin>>vote;
     
     switch(vote >= 1 && vote <= 5){
          case 1: 
                 ballot[vote]++;
                 break;
          default :
                 ballot[0]++;
     }
       votecount--;
     }
     for(int i = 0; i < 5; i++){
     cout <<"The vote for the candidate are :" <<ballot[i]<<endl;
     }
     return 0;
}