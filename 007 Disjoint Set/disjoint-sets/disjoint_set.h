
/* Include Guard */

#ifndef _DISJOINT_SETS_H_
#define _DISJOINT_SETS_H_

#include <bits/stdc++.h>

class DisjointSet {
private:
    size_t* parentOfObject;
    size_t* treeSize;
    size_t numberOfObjects;
    size_t numberOfComponents;
    size_t root(size_t p);
public:
    explicit DisjointSet(size_t countOfObjects);
    ~DisjointSet();
    void unionMethod(size_t p, size_t q);
    bool findMethod(size_t p, size_t q);
    size_t getNumberOfComponents() const;
    size_t getNumberOfObjects() const;
    size_t getComponentSize(size_t p);
};

/* constructor */
DisjointSet::DisjointSet(size_t countOfObjects)
:numberOfObjects{countOfObjects}, numberOfComponents{countOfObjects}{
    parentOfObject = new size_t[DisjointSet::numberOfObjects];

    /* initialize parent information of each object */
    for (size_t i{0};i < DisjointSet::numberOfObjects;i++) {
        DisjointSet::parentOfObject[i] = i;
    }

    DisjointSet::treeSize = new size_t[DisjointSet::numberOfObjects];

    /* initialize treeSize information of each tree */
    for (size_t i{0};i < DisjointSet::numberOfObjects;i++) {
        DisjointSet::treeSize[i] = 1;
    }
}

/* destructor */
DisjointSet::~DisjointSet() {
    /* de-allocate heap memory for
     * storing parent information */
    delete [] DisjointSet::parentOfObject;

    /* de-allocate heap memory for
     * storing treeSize information */
    delete [] DisjointSet::treeSize;
}

/* get numberOfComponents */
size_t DisjointSet::getNumberOfComponents() const {
    return DisjointSet::numberOfComponents;
}

/* get numberOfObjects */
size_t DisjointSet::getNumberOfObjects() const {
    return DisjointSet::numberOfObjects;
}

/* find root of connected component
 * which consist of the object(p) */
size_t DisjointSet::root(size_t p) {
    size_t rootOfTree{p};
    while (rootOfTree != DisjointSet::parentOfObject[rootOfTree]) {
        rootOfTree = DisjointSet::parentOfObject[rootOfTree];
    }

    /* perform path-compression */
    while (rootOfTree != p) {
        size_t nextParent{DisjointSet::parentOfObject[p]};
        DisjointSet::parentOfObject[p] = rootOfTree;
        p = nextParent;
    }

    return rootOfTree;
}

/* find whether object(p) and object(q)
 * are part of same connected component */
bool DisjointSet::findMethod(size_t p, size_t q) {
    return root(p) == root(q);
}

/* weighted union method */
void DisjointSet::unionMethod(size_t p, size_t q) {
    size_t rootOfObject_P{root(p)};
    size_t rootOfObject_Q{root(q)};

    /* if object(p) & object(q) aren't
     * of same connected component */
    if (rootOfObject_P != rootOfObject_Q) {
        if (DisjointSet::treeSize[rootOfObject_P] > DisjointSet::treeSize[rootOfObject_Q]) {
            DisjointSet::parentOfObject[rootOfObject_Q] = rootOfObject_P;
            DisjointSet::treeSize[rootOfObject_P] += treeSize[rootOfObject_Q];
        } else {
            DisjointSet::parentOfObject[rootOfObject_P] = rootOfObject_Q;
            DisjointSet::treeSize[rootOfObject_Q] += treeSize[rootOfObject_P];
        }
        DisjointSet::numberOfComponents -= 1;
    }
}

/* get size of connected component
 * in which the object(p) resides */
size_t DisjointSet::getComponentSize(size_t p) {
    return DisjointSet::treeSize[root(p)];
}

#endif