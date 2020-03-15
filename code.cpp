#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the gameWithCells function below.
 */
int gameWithCells(int n, int m) 
{
    int a1=0, a2=0, b=0, c=0, count=0;
    if(n==0 || m==0)
    {
        count=0;
    }
    else if(n==1 || m==1)
    {
        if(n>m)
        {
            count = n/2 + 1;
        }
        else
        {
            count = m/2 + 1;
        }
    }
    else if (n>=2 && m>=2)
    {
        a1=n/2;
        a2=m/2;
    }
    b = n*m - 4*(a1*a2);
    c = (b+1)/2;
    count = (a1*a2)+c;

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    int result = gameWithCells(n, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
