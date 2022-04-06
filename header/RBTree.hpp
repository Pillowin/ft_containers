#pragma once

#include "utility.hpp"
#include <cstdlib>
#include <iostream> // TODO: rm
#include <memory>
#include <utility>

/*
#include <stdio.h> //TODO: rm
#include <stdlib.h> //TODO: rm
#include <string.h> //TODO: rm
#include <strings.h> //TODO: rm
*/

namespace ft {

#define LEAF NULL

typedef enum {
	RED = 0,
	BLACK
} RBColor;

/*
# define SENTINEL 2

# define P_PAD " "
# define PAD " "

# define P_TRUNC "…"
# define TRUNC "+"

# define P_PREFIX "\033[33m☾\033[34m"
# define PREFIX "["

# define P_SUFFIX "\033[33m☽\033[0m"
# define SUFFIX "]"

# define P_JUNCTION "—"
# define JUNCTION "-"

# define P_JUNCTION_LOW_L "\033[35m╭"
# define JUNCTION_LOW_L "/"

# define P_JUNCTION_HIG_L "╯\033[0m"
# define JUNCTION_HIG_L "'"

# define P_JUNCTION_LOW_R "╮\033[0m"
# define JUNCTION_LOW_R ""

# define P_JUNCTION_HIG_R "\033[35m╰"
# define JUNCTION_HIG_R "`"

#define MAX_WORD_WIDTH 20
#define WORD_ADDED_WIDTH 2

#define node RBNode
#define val key

*/
template< class T >
class RBNode {
	public:
		typedef T					  value_type;
		typedef value_type&			  reference;
		typedef value_type const&	  const_reference;
		typedef value_type*			  pointer;
		typedef value_type const*	  const_pointer;
		typedef RBNode< value_type >* node_pointer;

		RBNode(void) :
			left(NULL),
			right(NULL),
			parent(NULL),
			color(BLACK),
			key() {}
		RBNode(T const& key) :
			left(NULL),
			right(NULL),
			parent(NULL),
			color(BLACK),
			key(key) {}
		RBNode(RBNode const& rhs) { *this = rhs; }
		~RBNode(void) {}
		RBNode& operator=(RBNode const& rhs) {
			if (this == &rhs)
				return (*this);
			this->left	 = rhs.left;
			this->right	 = rhs.right;
			this->parent = rhs.parent;
			this->color	 = rhs.color;
			this->key	 = rhs.key;
			return (*this);
		}

		node_pointer left;
		node_pointer right;
		node_pointer parent;
		RBColor		 color;
		value_type	 key;

		/*
		typedef enum e_style_match {
			E_PAD,
			E_TRUNC,
			E_PREFIX,
			E_SUFFIX,
			E_JUNCTION,
			E_JUNCTION_LOW_L,
			E_JUNCTION_LOW_R,
			E_JUNCTION_HIG_L,
			E_JUNCTION_HIG_R,
		}    t_style_match;

		typedef struct s_print_style{
			const char    *word;
			int        len;
		}                t_print_style;

		const t_print_style    g_pretty_style[10] = {
			[E_PAD] = {P_PAD, sizeof(P_PAD) - 1},
			[E_TRUNC] = {P_TRUNC, sizeof(P_TRUNC) - 1},
			[E_PREFIX] = {P_PREFIX, sizeof(P_PREFIX) - 1},
			[E_SUFFIX] = {P_SUFFIX, sizeof(P_SUFFIX) - 1},
			[E_JUNCTION] = {P_JUNCTION, sizeof(P_JUNCTION) - 1},
			[E_JUNCTION_LOW_L] = {P_JUNCTION_LOW_L, sizeof(P_JUNCTION_LOW_L) -
1}, [E_JUNCTION_LOW_R] = {P_JUNCTION_LOW_R, sizeof(P_JUNCTION_LOW_R) - 1},
			[E_JUNCTION_HIG_L] = {P_JUNCTION_HIG_L, sizeof(P_JUNCTION_HIG_L) -
1}, [E_JUNCTION_HIG_R] = {P_JUNCTION_HIG_R, sizeof(P_JUNCTION_HIG_R) - 1},
		};

		const t_print_style    g_basic_style[10] = {
			[E_PAD] = {PAD, 1},
			[E_TRUNC] = {TRUNC, 1},
			[E_PREFIX] = {PREFIX, 1},
			[E_SUFFIX] = {SUFFIX, 1},
			[E_JUNCTION] = {JUNCTION, 1},
			[E_JUNCTION_LOW_L] = {JUNCTION_LOW_L, 1},
			[E_JUNCTION_LOW_R] = {JUNCTION_LOW_R, 1},
			[E_JUNCTION_HIG_L] = {JUNCTION_HIG_L, 1},
			[E_JUNCTION_HIG_R] = {JUNCTION_HIG_R, 1},
		};

		typedef struct s_tree_display {
			int		block_width;
			int		block_delta;
			int		label_width;
			int		label_delta;
			int		lwidth;
			int		lpos;
			int		rwidth;
			int		rpos;
			int		trunc;
			int		depth;
			int		pos;
		}	t_tree_display;

		t_tree_display tree_dsp;

		typedef struct s_buf {
			char	*str;
			char	*s;
			int		capacity;
			int		pretty;
		}	t_buf;

		operator	node<const value_type>() const {
			return node<const value_type >(val);
		}
		bool operator==(const node &rhs) const { return val == rhs.val; }
		bool operator!=(const node &rhs) const { return val != rhs.val; }
		bool operator==(const value_type &rhs) const { return val == rhs; }
		bool operator!=(const value_type &rhs) const { return val != rhs; }

		static bool is_left_child(node *node) {
			return (!is_null_node(node->parent) && node->parent->left == node);
		}
		static bool is_right_child(node *node) {
			return (!is_null_node(node->parent) && node->parent->right == node);
		}
		static node *sibling(node* x) {
			if (is_left_child(x))
				return x->parent->right;
			return x->parent->left;
		}
		static bool getColor(node *x) {
			if (is_null_node(x))
				return BLACK;
			return x->color;
		}
		static bool is_null_node(node *x) {
//				std::cout << "x is " << x << " | color is " << (x != NULL ?
x->color : -1) << std::endl; return x == NULL || x->color == SENTINEL;
		}
		static void DG_tree(node *root) {
			_print_tree(root, 1, 2);
		}

		int	buffer_append_raw(t_buf *b, const char *src, int len)
		{
			const int	cur_len = b->s - b->str;

			if (cur_len + len >= b->capacity)
			{
				b->capacity += 5048;
				b->str = (char *)realloc(b->str, b->capacity);
				if (!b->str)
				{
					b->s = NULL;
					b->capacity = 0;
					return (1);
				}
				b->s = b->str + cur_len;
			}
			memcpy(b->s, src, len);
			b->s += len;
			return (0);
		}

		int	buffer_append(t_buf *b, t_style_match item)
		{
			if (b->pretty)
				return (buffer_append_raw(b, g_pretty_style[item].word,
											g_pretty_style[item].len));
			return (buffer_append_raw(b, g_basic_style[item].word,
										g_basic_style[item].len));
		}
		int	buffer_trim_to_newline(t_buf *b)
		{
			while (b->s > b->str && *(b->s - 1) == ' ')
				b->s--;
			return (buffer_append_raw(b, "\n", 1));
		}
		int	buffer_append_mul(t_buf *b, t_style_match item, int repeat)
		{
			int		ret;

			if (repeat < 0)
				return (0);
			ret = 0;
			while (!ret && repeat--)
				ret = buffer_append(b, item);
			return (ret);
		}
		int	buffer_connect_leaf(t_buf *b, int is_l, int len, int *cumul)
		{
			*cumul += len;
			if (is_l)
				return (buffer_append(b, E_JUNCTION_LOW_L)
						|| buffer_append_mul(b, E_JUNCTION, len - 2)
						|| buffer_append(b, E_JUNCTION_HIG_L)
						);
			return (buffer_append(b, E_JUNCTION_HIG_R)
					|| buffer_append_mul(b, E_JUNCTION, len - 2)
					|| buffer_append(b, E_JUNCTION_LOW_R));
		}
		int	print_connect(t_buf *b, int *printed)
		{
			int		print;
			int		ret;
			int		tmp;

			if (is_null_node(left))
				print = tree_dsp.pos - 1;
			else
				print = left->tree_dsp.pos + left->tree_dsp.block_delta - 1;
			ret = buffer_append_mul(b, E_PAD, print);
			if (ret || is_null_node(left))
				tmp = tree_dsp.lwidth;
			else
			{
				ret = buffer_connect_leaf(b, 1, tree_dsp.pos - print, &print);
				tmp = left->tree_dsp.block_width + left->tree_dsp.block_delta;
			}
			if (!ret && !is_null_node(right))
			{
				tmp = right->tree_dsp.pos + right->tree_dsp.block_delta + tmp
					- tree_dsp.pos + is_null_node(left);
				ret = buffer_connect_leaf(b, 0, tmp, &print);
			}
			*printed += print;
			tree_dsp.depth = 0;
			return (ret);
		}
		int	print_label(t_buf *b, int *printed)
		{
			int			ret;

			ret = buffer_append_mul(b, E_PAD, tree_dsp.label_delta)
				|| buffer_append(b, E_PREFIX)
				|| buffer_append_raw(b, color == RED ? "\033[31m" : "\033[34m",
sizeof("\033[31m") - 1)
				|| buffer_append_raw(b, val.to_string().c_str(),
tree_dsp.label_width - WORD_ADDED_WIDTH - tree_dsp.trunc)
				;
			if (!ret && tree_dsp.trunc)
				ret = buffer_append(b, E_TRUNC);
			if (!ret)
				ret = buffer_append(b, E_SUFFIX);
			*printed += tree_dsp.label_width + tree_dsp.label_delta;
			tree_dsp.depth = 2;
			return (ret);
		}
		int	layer_print_specific(t_buf *b, int (node::*layer_fn)(t_buf *b, int
*printed), int *ret)
		{
			int		print;

			if (*ret)
				return (0);
			print = tree_dsp.block_delta;
			*ret = buffer_append_mul(b, E_PAD, tree_dsp.block_delta);
			if (!*ret && tree_dsp.depth == 0)
			{
				if (!is_null_node(left))
					print += left->layer_print_specific(b, layer_fn, ret);
				else
				{
					print += tree_dsp.lwidth;
					*ret = buffer_append_mul(b, E_PAD, tree_dsp.lwidth);
				}
				if (!*ret && !is_null_node(right))
					print += right->layer_print_specific(b, layer_fn, ret);
			}
			else if (!*ret)
				*ret = (this->*layer_fn)(b, &print);
			if (!*ret)
				*ret = buffer_append_mul(b, E_PAD,
											tree_dsp.block_width +
tree_dsp.block_delta - print); return (tree_dsp.block_width +
tree_dsp.block_delta);
		}
		int	layer_print_tree(int max_depth, int fd, int pretty)
		{
			t_buf	b;
			int		ret;

			ret = 0;
			bzero(&b, sizeof(t_buf));
			b.pretty = pretty;
			while (!ret && max_depth >= 0)
			{
				layer_print_specific(&b, &node::print_label, &ret);
				if (!ret)
					ret = buffer_trim_to_newline(&b);
				if (max_depth--)
				{
					if (!ret)
						layer_print_specific(&b, &node::print_connect, &ret);
					if (!ret)
						ret = buffer_trim_to_newline(&b);
				}
			}
			if (!ret)
				ret = buffer_append_raw(&b, "\0", 1);
			if (!ret)
				dprintf(fd, "%s", b.str);
			free(b.str);
			return (ret);
		}

		void	label_adjust()
		{
			tree_dsp.label_delta = tree_dsp.pos - tree_dsp.label_width / 2 - 1;
			if (tree_dsp.label_delta < 0)
			{
				tree_dsp.pos -= tree_dsp.label_delta;
				tree_dsp.label_delta = 0;
			}
		}

		void	pos_calc(int depth_left, int depth_right)
		{
			tree_dsp.block_width = std::max(tree_dsp.lwidth + tree_dsp.rwidth +
1, tree_dsp.label_width); if (depth_left && depth_right) { t_tree_display *l =
&left->tree_dsp; t_tree_display *r = &right->tree_dsp; const int	lpos =
l->block_delta + std::max(l->pos + 1, l->pos + (l->label_width -
tree_dsp.label_width) / 2); const int	rpos = l->block_width + l->block_delta
+ r->block_delta + std::min(r->pos - 1, r->pos + (r->label_width -
tree_dsp.label_width) / 2); tree_dsp.pos = (lpos + rpos) / 2; } else if
(depth_left){ t_tree_display *l = &left->tree_dsp; tree_dsp.pos = l->block_delta
+ std::max(l->pos + 1, l->pos + (l->label_width - tree_dsp.label_width) / 2); if
(tree_dsp.lwidth > tree_dsp.label_width)
					--tree_dsp.block_width;
				tree_dsp.rwidth = tree_dsp.block_width - tree_dsp.lwidth;
			} else if (depth_right) {
				t_tree_display *r = &right->tree_dsp;
				const int	rpos = r->block_delta + std::min(r->pos - 1, r->pos
+ (r->label_width - tree_dsp.label_width) / 2); tree_dsp.pos = rpos; if
(tree_dsp.rwidth > tree_dsp.label_width)
					--tree_dsp.block_width;
				tree_dsp.lwidth = tree_dsp.block_width - tree_dsp.rwidth;
			}
			else
				tree_dsp.pos = tree_dsp.block_width / 2 + 1;
		}

		void	delta_adjust(int depth_left, int depth_right)
		{
			const int	delta = tree_dsp.label_width
				- (tree_dsp.lwidth + tree_dsp.rwidth + 1);

			if (!depth_left || !depth_right)
				return;
			if (delta > 0)
			{
				right->tree_dsp.block_delta = (delta + 1) / 2;
				left->tree_dsp.block_delta = delta -
right->tree_dsp.block_delta;
			}
			else
				right->tree_dsp.block_delta = 1;
		}

		void	init_calc()
		{
			bzero(&tree_dsp, sizeof(t_tree_display));
			tree_dsp.depth = 1;
			tree_dsp.label_width = val.to_string().size();

			if (tree_dsp.label_width > MAX_WORD_WIDTH)
				tree_dsp.trunc = 1;
			tree_dsp.label_width = std::min(tree_dsp.label_width,
MAX_WORD_WIDTH) + WORD_ADDED_WIDTH;
		}
		static int	_calc_depth(node *tree, int depth)
		{
			int				depth_left;
			int				depth_right;

			if (!tree || tree->color == SENTINEL)
				return (0);
			tree->init_calc();
			depth_left = _calc_depth(tree->left, depth + 1);
			depth_right = _calc_depth(tree->right, depth + 1);
			tree->tree_dsp.lwidth = depth_left ?
tree->left->tree_dsp.block_width : 0; tree->tree_dsp.rwidth = depth_right ?
tree->right->tree_dsp.block_width : 0; tree->delta_adjust(depth_left,
depth_right); tree->pos_calc(depth_left, depth_right); tree->label_adjust();
			return (std::max(depth, std::max(depth_left, depth_right)));
		}

		static int	_print_tree(node *root, int pretty, int fd)
		{
			int				ret;

			if (!root)
			{
				if (pretty)
					dprintf(fd, "\033[31mCannot print a NULL tree\033[0m\n");
				else
					dprintf(fd, "Cannot print a NULL tree\n");
				return (0);
			}
			ret = root->layer_print_tree(_calc_depth(root, 0), fd, pretty);
			if (ret)
			{
				if (pretty)
					dprintf(fd, "\033[31mMemory error while printing
tree\033[0m\n"); else dprintf(fd, "Memory error while printing tree");
			}
			return (ret);
		}
		*/
};

/*
template< class T >
std::ostream& operator<<(std::ostream& os, RBNode< T > const& rhs) {
	os << "Node:\t" << &rhs << std::endl;
	os << "\tkey: " << rhs.key.first << "\t\tvalue: " << rhs.key.second <<
std::endl;

	if (rhs.left)
		os << "\tleft: " << rhs.left->key.first << "\t\tvalue: " <<
rhs.left->key.second << std::endl; else os << "\tleft: LEAF" << std::endl;

	if (rhs.right)
		os << "\tright: " << rhs.right->key.first << "\tvalue: " <<
rhs.right->key.second << std::endl; else os << "\tright: LEAF" << std::endl;

	if (rhs.parent)
		os << "\tparent: " << rhs.parent->key.first << "\tvalue: " <<
rhs.parent->key.second << std::endl; else os << "\tparent: NONE" << std::endl;

	os << "\tcolor: " << (rhs.color == RED ? "RED" : "BLACK") << std::endl;
	return (os);
}
*/

template< class T,
		  class Compare,
		  class Allocator = std::allocator< RBNode< T > > >
class RBTree {
	public:
		typedef T				  value_type;
		typedef value_type&		  reference;
		typedef value_type const& const_reference;
		typedef Compare			  key_compare;
		typedef
			typename Allocator::template rebind< RBNode< value_type > >::other
													   allocator_type;
		typedef std::size_t							   size_type;
		typedef typename allocator_type::pointer	   pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef RBNode< value_type >				   node;
		typedef node*								   node_pointer;
		typedef typename value_type::first_type		   key_reference;

	private:
		allocator_type allocator;
		size_type	   size;
		key_compare	   comp;
		node_pointer   root;
		node_pointer   end;

	public:
		RBTree(void) :
			allocator(Allocator()),
			size(0),
			comp(Compare()),
			root(LEAF),
			end(this->create_node(LEAF)) {}
		RBTree(RBTree const& rhs) { *this = rhs; }
		~RBTree(void) {
			this->clear(this->root);
			this->delete_node(this->end);
		}

	private:
		RBTree& operator=(RBTree const& rhs) {
			(void)rhs;
			return (*this);
		}

	public:
		void insert(const_reference key) {
			node_pointer n = search(key.first);
			if (n != NULL)
				return;
			if (this->size)
				this->end->parent->right = LEAF;
			else
				this->root = LEAF;
			++this->size;
			node_pointer inserted_node = create_node(key);
			inserted_node->color	   = RED;
			if (this->root == NULL) {
				this->root = inserted_node;
			} else {
				node_pointer n = this->root;
				while (true) {
					if (this->comp(key.first, n->key.first) == true) {
						if (n->left == NULL && n->left != this->end) {
							n->left = inserted_node;
							break;
						} else {
							n = n->left;
						}
					} else {
						if (n->right == NULL && n->right != this->end) {
							n->right = inserted_node;
							break;
						} else {
							n = n->right;
						}
					}
				}
				inserted_node->parent = n;
			}
			insert_case1(inserted_node);
			update_end();
		}

		template< class InputIt >
		void insert(InputIt first, InputIt last) {
			for (; first != last; ++first)
				insert(*first);
		}

		void erase(key_reference k) {
			node_pointer n = search(k);
			if (n == NULL)
				return;
			if (this->size)
				this->end->parent->right = LEAF;
			else
				this->root = LEAF;
			--this->size;
			if (n->left != NULL && n->right != NULL) {
				// Copy key/value from predecessor and then delete it instead
				node_pointer pred = maximum(n->left);
				n->key			  = pred->key;
				n				  = pred;
			}
			node_pointer child = n->right == NULL ? n->left : n->right;
			if (get_color(n) == BLACK) {
				n->color = get_color(child);
				erase_case1(n);
			}
			replace_node(n, child);
			if (n->parent == NULL && child != NULL) // root should be black
				child->color = BLACK;
			delete_node(n);
			update_end();
		}
		void clear(node_pointer root) {
			if (root == LEAF || root == this->end) {
				this->size = 0;
				this->update_end();
				return;
			}
			clear(root->left);
			clear(root->right);
			delete_node(root);
		}
		node_pointer search(key_reference k) {
			node_pointer n = this->root;
			while (n != NULL) {
				if (k == n->key.first)
					return (n);
				else if (this->comp(k, n->key.first) == true)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}
		node_pointer search(key_reference k) const {
			node_pointer n = this->root;
			while (n != NULL) {
				if (k == n->key.first)
					return (n);
				else if (k < n->key.first)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}
		node_pointer maximum(node_pointer n) {
			while (n->right != NULL && n->right != this->end)
				n = n->right;
			return (n);
		}
		node_pointer maximum(node_pointer n) const {
			while (n->right != NULL && n->right != this->end)
				n = n->right;
			return (n);
		}
		node_pointer minimum(node_pointer n) {
			if (this->size == 0)
				return (this->end);
			while (n->left != NULL)
				n = n->left;
			return (n);
		}
		node_pointer minimum(node_pointer n) const {
			if (this->size == 0)
				return (this->end);
			while (n->left != NULL)
				n = n->left;
			return (n);
		}
		void swap(RBTree& tree) {
			allocator_type tmp_allocator = tree.allocator;
			size_type	   tmp_size		 = tree.size;
			key_compare	   tmp_comp		 = tree.comp;
			node_pointer   tmp_root		 = tree.root;
			node_pointer   tmp_end		 = tree.end;

			tree.allocator = this->allocator;
			tree.size	   = this->size;
			tree.comp	   = this->comp;
			tree.root	   = this->root;
			tree.end	   = this->end;

			this->allocator = tmp_allocator;
			this->size		= tmp_size;
			this->comp		= tmp_comp;
			this->root		= tmp_root;
			this->end		= tmp_end;
		}
		allocator_type get_allocator(void) const { return (this->allocator); }
		size_type	   get_size(void) const { return (this->size); }
		node_pointer   get_root(void) const { return (this->root); }
		node_pointer   get_end(void) const { return (this->end); }

	private:
		/* Create/Delete */
		node_pointer create_node(const_reference v) {
			node_pointer n = this->allocator.allocate(1);
			this->allocator.construct(n, node(v));
			return (n);
		}
		node_pointer create_node(node_pointer p) {
			node_pointer n = this->allocator.allocate(1);
			if (p != NULL)
				this->allocator.construct(n, node(*p));
			else
				this->allocator.construct(n, node());
			return (n);
		}
		void delete_node(node_pointer n) {
			this->allocator.destroy(n);
			this->allocator.deallocate(n, 1);
		}

		/* Genealogy */
		node_pointer parent(node_pointer n) { return (n->parent); }
		node_pointer grandparent(node_pointer n) {
			node_pointer p = parent(n);
			if (p == NULL)
				return (NULL); // Un noeud sans parent n'a pas de grand-parent
			return parent(p);
		}
		node_pointer sibling(node_pointer n) {
			node_pointer p = parent(n);
			if (p == NULL)
				return (NULL); // Un noeud sans parent n'a pas de frere
			if (n == p->left)
				return (p->right);
			else
				return (p->left);
		}
		node_pointer uncle(node_pointer enfant) { // Renvoie le frère du père
			node_pointer p = parent(enfant);
			node_pointer g = grandparent(enfant);
			if (g == NULL)
				return (NULL); // Pas de grand parent, donc pas d'uncle
			return (sibling(p));
		}

		/* Rotations */
		void rotate_left(node_pointer n) {
			node_pointer r = n->right;
			replace_node(n, r);
			n->right = r->left;
			if (r->left != NULL) {
				r->left->parent = n;
			}
			r->left	  = n;
			n->parent = r;
		}
		void rotate_right(node_pointer n) {
			node_pointer l = n->left;
			replace_node(n, l);
			n->left = l->right;
			if (l->right != NULL)
				l->right->parent = n;
			l->right  = n;
			n->parent = l;
		}

		/* Utils */
		RBColor get_color(node_pointer n) {
			return (n == NULL ? BLACK : n->color);
		}
		void replace_node(node_pointer oldn, node_pointer newn) {
			if (oldn->parent == NULL) {
				this->root = newn;
			} else {
				if (oldn == oldn->parent->left)
					oldn->parent->left = newn;
				else
					oldn->parent->right = newn;
			}
			if (newn != NULL) {
				newn->parent = oldn->parent;
			}
		}
		void update_end(void) {
			if (this->size == 0) {
				if (this->end == NULL)
					this->end = this->create_node(LEAF);
				this->root = this->end;
				return;
			}
			node_pointer max  = this->maximum(this->root);
			max->right		  = this->end;
			this->end->parent = max;
		}

		/* Insert */
		void insert_case1(node_pointer n) {
			if (n->parent == NULL)
				n->color = BLACK;
			else
				insert_case2(n);
		}
		void insert_case2(node_pointer n) {
			if (get_color(n->parent) == BLACK)
				return; // Tree is still valid
			else
				insert_case3(n);
		}
		void insert_case3(node_pointer n) {
			if (get_color(uncle(n)) == RED) {
				n->parent->color	  = BLACK;
				uncle(n)->color		  = BLACK;
				grandparent(n)->color = RED;
				insert_case1(grandparent(n));
			} else {
				insert_case4(n);
			}
		}
		void insert_case4(node_pointer n) {
			if (n == n->parent->right && n->parent == grandparent(n)->left) {
				rotate_left(n->parent);
				n = n->left;
			} else if (n == n->parent->left
					   && n->parent == grandparent(n)->right) {
				rotate_right(n->parent);
				n = n->right;
			}
			insert_case5(n);
		}
		void insert_case5(node_pointer n) {
			n->parent->color	  = BLACK;
			grandparent(n)->color = RED;
			if (n == n->parent->left && n->parent == grandparent(n)->left) {
				rotate_right(grandparent(n));
			} else {
				rotate_left(grandparent(n));
			}
		}

		/* Erase */
		void erase_case1(node_pointer n) {
			if (n->parent == NULL)
				return;
			else
				erase_case2(n);
		}
		void erase_case2(node_pointer n) {
			if (get_color(sibling(n)) == RED) {
				n->parent->color  = RED;
				sibling(n)->color = BLACK;
				if (n == n->parent->left)
					rotate_left(n->parent);
				else
					rotate_right(n->parent);
			}
			erase_case3(n);
		}
		void erase_case3(node_pointer n) {
			if (get_color(n->parent) == BLACK && get_color(sibling(n)) == BLACK
				&& get_color(sibling(n)->left) == BLACK
				&& get_color(sibling(n)->right) == BLACK) {
				sibling(n)->color = RED;
				erase_case1(n->parent);
			} else
				erase_case4(n);
		}
		void erase_case4(node_pointer n) {
			if (get_color(n->parent) == RED && get_color(sibling(n)) == BLACK
				&& get_color(sibling(n)->left) == BLACK
				&& get_color(sibling(n)->right) == BLACK) {
				sibling(n)->color = RED;
				n->parent->color  = BLACK;
			} else
				erase_case5(n);
		}
		void erase_case5(node_pointer n) {
			if (n == n->parent->left && get_color(sibling(n)) == BLACK
				&& get_color(sibling(n)->left) == RED
				&& get_color(sibling(n)->right) == BLACK) {
				sibling(n)->color		= RED;
				sibling(n)->left->color = BLACK;
				rotate_right(sibling(n));
			} else if (n == n->parent->right && get_color(sibling(n)) == BLACK
					   && get_color(sibling(n)->right) == RED
					   && get_color(sibling(n)->left) == BLACK) {
				sibling(n)->color		 = RED;
				sibling(n)->right->color = BLACK;
				rotate_left(sibling(n));
			}
			erase_case6(n);
		}
		void erase_case6(node_pointer n) {
			sibling(n)->color = get_color(n->parent);
			n->parent->color  = BLACK;
			if (n == n->parent->left) {
				sibling(n)->right->color = BLACK;
				rotate_left(n->parent);
			} else {
				sibling(n)->left->color = BLACK;
				rotate_right(n->parent);
			}
		}
};

} // namespace ft
