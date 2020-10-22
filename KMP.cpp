string pat;
const int maxn = 1e6 + 5;
int lps[maxn+5];

void computeLPSArray(){
    int m = pat.size();
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    int j = 0; // lps of previous

    while(i<m){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            j++; i++;
        }
        else{
            if(j==0){
                lps[i]=0;i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
}

void kmpSearch(string str){
    int i=0,j=0;
    int n = sz(str), m = sz(pat);
    while(i<n){
        if(str[i]==pat[j]){
            i++; j++;
            if(j==m){
                cout<<"Found pattern at index "<<i-m<<endl;
            }
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }

}
void solve()
{
    string str;
    rd(str, pat);
    computeLPSArray();
    show(lps, pat.size());
    kmpSearch(str);
}
