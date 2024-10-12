using namespace std;

int main()
{
    int matriz[5][2], l, c, produto=1;
    
    for(l=0;l<5;l++)
    {
        for(c=0;c<2;c++)
        {
            cin>>matriz[l][c];
            
            produto = produto*matriz[l][c];
        }
    }
    
    cout<<"Produto dos valores da matriz: "<<produto;
    

    return 0;
}