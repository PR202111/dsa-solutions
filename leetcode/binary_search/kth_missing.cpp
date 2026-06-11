int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> missing(n);
        missing[0] = arr[0] - 1;
        for(int i=1;i<n;i++){
            missing[i] = arr[i] - arr[i-1] - 1 + missing[i-1];

        }
        int l = 0;
        int r = arr.size() - 1;
        int idx = n;
        while(r>=l){
            int mid = l + (r-l)/2;
            if(missing[mid] >= k){
                idx = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        if(idx == n){
            return arr[n-1] + k - missing[n-1];
        }
        else if(idx == 0) return k;

        return arr[idx-1]+k-missing[idx-1];

    }