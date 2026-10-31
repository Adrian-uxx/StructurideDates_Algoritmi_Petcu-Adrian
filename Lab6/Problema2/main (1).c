#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderHelper(struct TreeNode* root,
                   int* result,
                   int* index) {

    if (root == NULL) {
        return;
    }

    inorderHelper(root->left, result, index);

    result[(*index)++] = root->val;

    inorderHelper(root->right, result, index);
}

void countNodes(struct TreeNode* root, int* count) {
    if (root == NULL) return;

    (*count)++;

    countNodes(root->left, count);
    countNodes(root->right, count);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int count = 0;

    countNodes(root, &count);

    *returnSize = count;

    if (count == 0) {
        return NULL;
    }

    int* result = malloc(count * sizeof(int));

    if (result == NULL) {
        exit(1);
    }

    int index = 0;

    inorderHelper(root, result, &index);

    return result;
}

int main() {

    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n2 = {2, &n1, &n3};

    int returnSize;

    int* result = inorderTraversal(&n2, &returnSize);

    printf("Inorder traversal: [");

    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);

        if (i < returnSize - 1) {
            printf(", ");
        }
    }

    printf("]\n");

    free(result);

    return 0;
}