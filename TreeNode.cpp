struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  bool isOperator(char c){
      return c == '+' || c == '-' || c == '*' || c == '/';
  }
  bool greaterPrecedence(char parent, char child){
      if ((parent == '*' || parent == '/') && (child == '+' || child == '-'))
          return true;
      return false;
  }
  TreeNode* treeFromPostfix(string postfix){
      stack<TreeNode*>st;
      auto lastOperand = new TreeNode();
      for (auto &c: postfix){
          auto operandNode = new TreeNode(c);
          lastOperand = operandNode;
          if (isOperator(c)){
              operandNode->right = st.top();
              st.pop();
              operandNode->left = st.top();
              st.pop();
              st.push(operandNode);
          }
          else
              st.push(operandNode);
      }
      return lastOperand;
  }
    void printTree(TreeNode* root, int depth = 0) {
        if (!root)
            return;

        const int spacing = 4; // Adjust spacing for levels
        printTree(root->right, depth + 1);
        std::cout << std::string(depth * spacing, ' ') << root->val << endl;
        printTree(root->left, depth + 1);
    }
    void printTree2(TreeNode* root, int depth = 0) {
        if (!root)
            return;

        const int spacing = 4; // Adjust spacing for levels

        printTree(root->right, depth + 1);
        std::cout << std::string(depth * spacing, ' ') << root->val << endl;
        printTree(root->left, depth + 1);
    }


    void prefixOrder(TreeNode* node){
      if (!node)
          return;
      cout << node->val;
      prefixOrder(node->left);
      prefixOrder(node->right);
  }
  void prefixOrderSymmetry(TreeNode* node){
      if (!node)
          return;
      cout << node->val;
      prefixOrderSymmetry(node->right);
      prefixOrderSymmetry(node->left);
  }
    void infixOrder(TreeNode* node){
        if (!node)
            return;
        infixOrder(node->left);
        cout << node->val;
        infixOrder(node->right);
    }
    void infixOrderSymmetry(TreeNode* node){
      if (!node)
          return;
        infixOrderSymmetry(node->right);
        cout << node->val;
        infixOrderSymmetry(node->left);
  }
    void infixWithBraces(TreeNode* node,bool leftChild = false, TreeNode* parent = nullptr){
        if (!node)
            return;
        if (parent && isOperator(node->val) && (greaterPrecedence(parent->val, node->val) || !leftChild)){
            cout << "(";
            infixWithBraces(node->left, true, node);
            cout << node->val;
            infixWithBraces(node->right, false,node);
            cout << ")";
        }
        else{
            infixWithBraces(node->left, true,node);
            cout << node->val;
            infixWithBraces(node->right,false, node);
        }
    }
    void postfixOrder(TreeNode* node){
        if (!node)
            return;
        postfixOrder(node->left);
        postfixOrder(node->right);
        cout << node->val;
    }
    bool is_just_num() {
        // If it has no children, then it is just a number
        return !left && !right;
    }
    void print_inorder_expression() {
        if (left) {
            if (!left->is_just_num())
                cout << "(";
            left->print_inorder_expression();
            if (!left->is_just_num())
                cout << ")";
        }

        cout << val;

        if (right) {
            if (!right->is_just_num())
                cout << "(";
            right->print_inorder_expression();
            if (!right->is_just_num())
                cout << ")";
        }
    }

};
