#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
#define debug(...) printf( __VA_ARGS__) 
#else
#define debug(...)
#endif

struct trie_node {
	struct trie_node 	*child[256];	/* 分支节点的孩子指针 */
	int  				count;	/* 用于记录单词出现的次数，若count大于0，说明
				   				   从根节点到此节点的父节点构成了一个单词，这个
				   				   单词的次数就是count */
};

int n;	/* 树的总数 */

struct trie_node *init_trie_tree()
{
	return (struct trie_node *)calloc(1, sizeof(struct trie_node));
}

void insert(struct trie_node *root, char *word)
{
	struct trie_node 	*node;
	char 				*p;

	node = root;
	debug("%s.......\n", word);
	for (p = word; *p; p++) {
		debug("开始插入%c\n", *p);
		if (node->child[*p] == 0) {
			debug("%c不存在,创建新节点\n", *p);
			node->child[*p] = (struct trie_node *)calloc(1, sizeof(struct trie_node));
		}
		else {
			debug("%c存在\n", *p);
		}
		node = node->child[*p];
	}
	//到达记录统计单词次数的节点
	node->count++;
	debug("%s有%d个\n\n", word, node->count);
}

/* 借助pos指针来遍历每个单词，初始时pos指向worddump的第一个位置
 * 若往孩子节点走，则pos后移，若往兄弟节点走，则pos保持不动 
 */
void dfs_travel(struct trie_node *root)
{
	static char 	worddump[31];
	static int 	 	pos;
	int 			i;

	if (root->count) {	/* 如果count不为0，则肯定找到了一个单词 */
		worddump[pos] = '\0';
		if (worddump[0]) {
			printf("%s %0.4f\n", worddump, ((float)root->count*100)/(float)n);
		}
	}
	for (i = 0; i < 256; i++) {
		if (root->child[i]) {
			debug("找到%c\n", i);
			worddump[pos++] = i; 	/* 往下遍历，pos跟着后移，供孩子节点使用 */
			dfs_travel(root->child[i]);
			pos--;	/* 恢复位置,供下一个兄弟节点使用 */
			debug("回退1个位置\n");
		}
	}
}

int main()
{
	char 				line[31];
	struct trie_node 	*root;

	n = 0;
	root = init_trie_tree();
	while (scanf("%s",&line)!=EOF) {
		insert(root, line);
		n++;
	}
	dfs_travel(root);

	return 0;
}
