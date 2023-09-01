int countSubStrings(string str, int k) 
{
    int n=str.length();
    int count=0;
    for(int i=0;i<n;i++){
        int dis_count=0;
        int arr[26]={0};
        for(int j=i;j<n;j++){
            int index=str[j]-'a';
            if(arr[index]==0){
                dis_count++;
            }
            arr[index]++;
            if(dis_count==k){
                count++;
            }
            if(dis_count>k){
                break;
            }
        }
    }
    return count;
}
