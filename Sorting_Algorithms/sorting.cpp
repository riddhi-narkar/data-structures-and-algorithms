#include<vector>
#include<algorithm>

void selection(std::vector<int> &v)
{
    int size = v.size(), index;

    for(int i = 0; i < size; i++)
    {
        index = *min_element(v.begin(), v.end());
        std::swap(index, v[i]);
    }

}