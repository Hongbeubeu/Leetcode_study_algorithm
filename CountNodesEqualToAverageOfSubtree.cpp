#include <utility>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        int result = 0;
        calculate(root, result);

        return result;
    }

    pair<int, int> calculate(TreeNode *node, int &result)
    {
        if (!node)
        {
            return {0, 0};
        }
        auto [left_sum, left_count] = calculate(node->left, result);
        auto [right_sum, right_count] = calculate(node->right, result);
        auto sum = node->val + left_sum + right_sum;
        auto count = 1 + left_count + right_count;
        if (sum / count == node->val)
            result++;
        return {sum, count};
    }
};

//https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/submissions/1089554429/?envType=daily-question&envId=2023-11-02
/*
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWNNNNNWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOkdooollllllllllllooodxOKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNKOdollllodxO0KKXXXXXXXXKK0Okdoolllldk0NWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMNKxlccldkKNWMMMMMMMMMMMMMMMMMMMMMMMMWNKOdolcldONMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMNOoccoxKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkocclkXWMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMNOo:cd0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxl:lkXMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMXxc:d0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXxc:o0WMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWKd:ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o:lOWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMXo;l0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKd;l0WMMMMMMMMMMMMM
MMMMMMMMMMMMNx;cOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK0OOOO0KXNKo;oKMMMMMMMMMMMM
MMMMMMMMMMW0c;kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxollllooooollllol,;kNMMMMMMMMMM
MMMMMMMMMNx;lKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxccox0NWMMMMMMWNXOdc;..lXMMMMMMMMM
MMMMMMMMXl;xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd;cONMMMMMMMMMMMMMMMMNk;  ;0WMMMMMMM
MMMMMMMKc;OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0::OWMMMMMMMMMMMMMWN0xolc:c;.,OWMMMMMM
MMMMMMKc;OWMMMMMMMMMMWX0kxdddddxk0XWMMMMMMMMMMMMMMMMMMMMMMMMM0;:KMMMMMMMMMMMNKkdlc:clodxkkl.,OWMMMMM
MMMMMXc;OWMMMMMMMWXkollloodxxxdoollcokXWMMMMMMMMMMMMMMMMMMMMNl,OMMMMMMMWKOdlc::coxkd;..,lxkc.,0MMMMM
MMMMWo,xWMMMMMMW0o:cd0NWMMMMMMMMMWN0dl:l0WMMMMMMMMMMMMMMMMMMK;cNMMWXOxocc:codxkkkkx;    .oko. :XMMMM
MMMMk,oNMMMMMMXo;o0WMMMMMMMMMMMMMMWNKx;.'oKWMMMMMMMMMMMMMMMMK;;kxolc:cldxkkkkkkkkkko,...cxko,.'oWMMM
MMMXc;KMMMMMM0::OWMMMMMMMMMMMMWXOxlc::loo;:0WMMMMMMMMMMMMMMMNl.,:ldxkkkkkkkkkkkkkkkkxddxkkkc,dl,OMMM
MMMk,dWMMMMMK::KMMMMMMMMMMWKkolc:cldxkkkkd;:KMMMMMMMMMMMMMMMM0;;dkkkkkkkkkkkkkkkkkkkkkkkkkl,oNO,lNMM
MMNc;0MMMMMWd,xWMMMMMWN0xocc:coxkxc,.'cxkko,dWMMMMMMMMMMMMMMMW0:;okkkkkkkkkkkkkkkkkkkkkkxc,oXMNc;0MM
MM0,cNMMMMMWl,0MMWXOdlc:cldxkkkkko.   .lkkd,lNMMMMMMMMMMMMMMMMMXo;:oxkkkkkkkkkkkkkkkkkxc;cOWMMWx,xMM
MMk,dWMMMMMWd,okolc:coxkkkkkkkkkkxc'..:dkko,oWMMMMMMMMMMMMMMMMMMWKdc::ldxkkkkkkkkxxoc::lkNMMMMMO,oWM
MWx,kMMMMMMM0,.;ldxkkkkkkkkkkkkkkkkxxxkkkx:;0MMMMMMMMMMMMMMMMMMMMMMN0xolccc:cc::ccclokXWMMMMMMM0;cNM
MWd,kMMMMMMMWk;:xkkkkkkkkkkkkkkkkkkkkkkkx:;kWMMMMMMMMMMMMMMMMMMMMMMMMMMWXK0OOkOO0XNWMMMMMMMMMMMK;cXM
MWd,kMMMMMMMMWOc;lxkkkkkkkkkkkkkkkkkkkxl;:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;cNM
MMk,xMMMMMMMMMMXxc;cdxkkkkkkkkkkkkkxdc;:xXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,lWM
MMO,lWMMMMMMMMMMMNOocc:cloodddoolc::coONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd'dWM
MMX::XMMMMMMMMMMMMMMWKOxdolllllodxOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0d:.'OMM
MMWd,kMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOdccoo'cXMM
MMMK;cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkoccdONWd,kMMM
MMMWd,xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0dlclx0WMMM0;cXMMM
MMMMXc;0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0dlccoOXWMMMMMXc;0MMMM
MMMMM0;cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKkolclokXWMMMMMMMMNo,xWMMMM
MMMMMWO;cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kollcldOXWMMMMMMMMMMMWd,dNMMMMM
MMMMMMWO;cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOxdlllloxOXWMMMMMMMMMMMMMMMNd,dNMMMMMM
MMMMMMMWO::0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNXK0kxdollllloxOKNWMMMMMMMMMMMMMMMMMMMXo,xNMMMMMMM
MMMMMMMMMKc;kNWWWWWWWWWWWWWNNNNXXXKK00Okkxddooolllllloooxk0KNWMMMMMMMMMMMMMMMMMMMMMMMMW0c;OWMMMMMMMM
MMMMMMMMMMXd;;cooooooooolllllllllllllooooodxkO0KXNNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx;lKMMMMMMMMMM
MMMMMMMMMMMW0:'cOKKKKKKXXXXXNNNNWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOc:xNMMMMMMMMMMM
MMMMMMMMMMMMMNk::kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0l;dXMMMMMMMMMMMMM
MMMMMMMMMMMMMMMXx:cxXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOl:oKWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMNkc:o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxc:dKWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMN0o:cd0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkl:lkNMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMNOoccoOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0dlclxKWMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMN0dlclok0NWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOdlccokXWMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOxolllodxOKXNWWMMMMMMMMMMWWNNK0kdolllldkKWMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kdolllllloooooooooollllllodk0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXKK00OOOOOO00KKXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
*/