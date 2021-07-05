#include "binary-tree.h"

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    BinaryTree<int32_t> binary_tree;
    binary_tree.insertElement(34);
    binary_tree.insertElement(19);
    binary_tree.insertElement(57);
    binary_tree.insertElement(12);
    binary_tree.insertElement(97);
    binary_tree.insertElement(2);

    std::cout << "pre-order: ";
    binary_tree.preOrder();

    std::cout << "in-order: ";
    binary_tree.inOrder();

    std::cout << "post-order: ";
    binary_tree.postOrder();

    std::cout << "level-order: ";
    binary_tree.levelOrder();

    auto item{binary_tree.searchElement(2)};
    if (item.first) {
        std::cout<< "\n"<< item.second->getData()<<std::endl;
        binary_tree.deleteElement(item.second->getData());
    }

    /* display tree */
    binary_tree.inOrder();

    std::cout << "height: " << binary_tree.heightOfBinaryTree() << std::endl;
    std::cout << "size_of_tree: " << binary_tree.getSizeOfTree() << std::endl;
    return 0;
}