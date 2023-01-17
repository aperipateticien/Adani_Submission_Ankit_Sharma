#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> MatrixGenerator(int rows,int cols){
    srand(time(0)); 
    vector<vector<int>> arr( rows , vector<int> (cols)); 
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            arr[i][j] = 0+(rand() % 100);
    
    return arr;
    
    
}

vector<vector<int> > MatrixTranspose(vector<vector<int> > v,int rows, int cols)
{

    vector<vector<int> > temp(cols, vector<int>(rows));
 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[j][i] = v[i][j];
        }
    }
 
    return temp;
}

void MatrixRow(vector<vector<int> >& v)
{
    for (int i = 0; i < (int)v.size(); i++) {

        sort(v[i].begin(), v[i].end());
    }
}

vector<vector<int> > MatrixColumn(vector<vector<int> > mat,int rows, int cols)
{
    vector<vector<int> > ans= MatrixTranspose(mat, rows, cols);
    MatrixRow(ans);

    mat = MatrixTranspose(ans, cols, rows);

    return mat;
}




int main(){
    
    int rows=0;
    int cols=0;
    cin>>rows>>cols;
    vector<vector<int>> ans;
   ans =  MatrixGenerator(rows,cols);
   
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
    vector<vector<int>> ans2;
    ans2 = MatrixColumn(ans,rows,cols);
    
    cout<<"\nAfter changes\n\n";
    
    
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++)
            cout << ans2[i][j] << " ";
        cout << endl;
    }
    return 0;   
}