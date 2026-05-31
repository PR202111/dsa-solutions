#include <iostream>
using namespace std;

void print_vector(vector<int>& nums){
    cout << "Array => ";
    for(int num:nums){
        cout << num << " ";
    }
    cout << "\n";
}

void move_left(vector<vector<int>>& matrix,vector<int>& ans,
pair<int,int>& ul,pair<int,int>& ur){
    for(int i = ul.second;i<=ur.second;i++){
        ans.push_back(matrix[ul.first][i]);
    }
}
void move_right(vector<vector<int>>& matrix,vector<int>& ans,
pair<int,int>& bl,pair<int,int>& br){
    for(int i = br.second;i>=bl.second;i--){
        ans.push_back(matrix[bl.first][i]);
    }
}
void move_up(vector<vector<int>>& matrix,vector<int>& ans,
pair<int,int>& ul,pair<int,int>& bl){
    for(int i = bl.first;i>=ul.first;i--){
        ans.push_back(matrix[i][ul.second]);
    }
}
void move_down(vector<vector<int>>& matrix,vector<int>& ans,
pair<int,int>& ur,pair<int,int>& br){
    for(int i = ur.first;i<=br.first;i++){
        ans.push_back(matrix[i][ur.second]);
    }
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix.empty() ? 0 : matrix[0].size();
    pair<int,int> ul = {0,0};
    pair<int,int> ur = {0,n-1};
    pair<int,int> bl = {m-1,0};
    pair<int,int> br = {m-1,n-1};
    while(ul.first <= bl.first && ul.second <= ur.second){
        move_left(matrix,ans,ul,ur);
        ul.first++;
        ur.first++;
        move_down(matrix,ans,ur,br);
        ur.second--;
        br.second--;
        
        if(ul.first <= bl.first){
            move_right(matrix, ans, bl, br);

            bl.first--;
            br.first--;
        }

        
        if(ul.second <= ur.second){
            move_up(matrix, ans, ul, bl);

            ul.second++;
            bl.second++;
        }
    }
    
    return ans;
}

vector<int> optimized(vector<vector<int>>& matrix){
    vector<int> ans;
    int m = matrix.size();
    int n = matrix.empty() ? 0 : matrix[0].size();
    int left = 0,top = 0;
    int right = n-1,bottom = m-1;
    while(right>=left && bottom >= top){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        for(int i=top+1;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        if(right > left){
            for(int i=right-1;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
        }
        if(bottom > top){
            for(int i=bottom-1;i>=top+1;i--){
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }

    return ans;
}


int main(){
    int m,n;
    cout << "Enter dimension (m X n): ";
    cin >>m >> n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> spiral_result = optimized(matrix);
    print_vector(spiral_result);

}