#include "binary-search-tree.h"

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    BinarySearchTree<int32_t> binarySearchTree;

    binarySearchTree.insertElement(34);
    binarySearchTree.insertElement(4);
    binarySearchTree.insertElement(21);
    binarySearchTree.insertElement(89);
    binarySearchTree.insertElement(17);
    binarySearchTree.insertElement(12);
    binarySearchTree.treeSort();

    binarySearchTree.deleteTree();
    binarySearchTree.treeSort();

    std::cout << binarySearchTree.getSizeOfTree() << "\n";

    binarySearchTree.insertElement(new Node<int32_t>(67));
    binarySearchTree.insertElement(new Node<int32_t>(43));
    binarySearchTree.insertElement(new Node<int32_t>(91));
    binarySearchTree.insertElement(new Node<int32_t>(12));
    binarySearchTree.insertElement(new Node<int32_t>(50));
    binarySearchTree.treeSort();

    binarySearchTree.deleteElement(43);
    binarySearchTree.treeSort();
    auto item{binarySearchTree.searchElement(12)};
    if (item.first) {
        std::cout << item.second->getData() << "\n";
    }
    return 0;
}