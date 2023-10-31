class Solution
{
public:
    int mySqrt(int x)
    {
        unsigned int sqrt = 0;
        unsigned int result = 0;
        while (result < x)
        {
            sqrt++;
            result = sqrt * sqrt;
        }
        if (result == x)
            return sqrt;
        return sqrt - 1;
    }
};