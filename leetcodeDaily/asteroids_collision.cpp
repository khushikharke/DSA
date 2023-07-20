class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> s;
        for (int asteroid : asteroids)
        {
            int flag = 1;
            while (!s.empty() && s.top() > 0 && asteroid < 0)
            {
                if (abs(s.top()) < abs(asteroid))
                {
                    s.pop();
                    continue;
                }
                else if (abs(s.top() == abs(asteroid)))
                {
                    s.pop();
                    flag = 0;
                }
                // will destroy curr asteroid
                flag = 0;
                break;
            }
            if (flag)
            {
                s.push(asteroid);
            }
        }
        vector<int> rem(s.size());
        for (int i = rem.size() - 1; i >= 0; i--)
        {
            rem[i] = s.top();
            s.pop();
        }
        return rem;
    }
};