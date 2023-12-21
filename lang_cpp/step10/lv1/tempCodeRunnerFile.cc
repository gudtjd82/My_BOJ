for(int i = 0; i < 9; i ++)
    {
        cout << i+1 << " 번째 col :";
        for(const auto& elem : col[i])
        {
            cout << " " << e