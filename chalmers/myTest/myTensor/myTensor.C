#include "fvMesh.H"        // 有限体积网格
// #include "volFields.H"     // 体场（volScalarField/volVectorField/…）
// #include "surfaceFields.H" // 面场（surfaceScalarField/…）

using namespace Foam;

int main()
{
    // 定义一个张量场 tf1，包含 2 个元素（即 2 个张量），
    tensorField tf1(2, tensor::one);

    // 输出整个张量场 tf1
    Info<< "tf1: " << tf1 << endl;

    // 修改张量场 tf1 的第一个元素（下标从 0 开始），
    tf1[0] = tensor(1, 2, 3, 4, 5, 6, 7, 8, 9);

    // 再次输出 tf1，此时第一个张量已被修改，第二个张量仍然是单位张量
    Info<< "tf1: " << tf1 << endl;

    // 将整个张量场乘以 2.0，得到一个新的张量场（不会修改 tf1 本身）
    Info<< "2.0*tf1: " << 2.0*tf1 << endl;

}