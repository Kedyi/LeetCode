class Solution {
public:
    string addBinary(string a, string b) {
        int     q = '0';
        string sum = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0;
        while (i < a.length() || i < b.length())
        {
            if (i < a.length() && i < b.length())
                sum += (a[i] + b[i] + q - 3 * '0') % 2 + '0',
                q = (a[i] + b[i] + q - 3 * '0' > 1) + '0';
            else if (i < a.length())
                sum += (a[i] + q - 2 * '0') % 2 + '0',
                q = (a[i] + q - 2 * '0' > 1) + '0';
            else
                sum += (b[i] + q - 2 * '0') % 2 + '0',
                q = (b[i] + q - 2 * '0' > 1) + '0';
            i++;
        }
        if (q == '1')
            sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};