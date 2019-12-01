#pragma once

#include <memory>
#include <vector>
//#include <iostream>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;
		static std::vector<T> Recurse(const std::shared_ptr<TreeNode<T>> node, unsigned int i);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		bool bCheck = false;

		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
		}
		else
		{
			auto temp = mRoot;
			std::shared_ptr<TreeNode<T>> before = nullptr;

			while (temp != nullptr)
			{
				if (*(temp->Data) < *data)
				{
					before = temp;
					temp = temp->Right;
					bCheck = false;
				}
				else if (*(temp->Data) > *data)
				{
					before = temp;
					temp = temp->Left;
					bCheck = true;
				}	
			}

			temp = std::make_shared<TreeNode<T>>(before, std::move(data));
			if (bCheck)
			{
				before->Left = temp;
			}
			else
			{
				before->Right = temp;
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		std::shared_ptr<TreeNode<T>> n = mRoot;
		return n;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		auto temp = mRoot;
		std::shared_ptr<TreeNode<T>> before = nullptr;

		while (temp != nullptr)
		{
			if (*(temp->Data) == data)
			{
				return true;
			}
			else if (*(temp->Data) < data)
			{
				before = temp;
				temp = temp->Right;
			}
			else if (*(temp->Data) > data)
			{
				before = temp;
				temp = temp->Left;
			}
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		//if (!Search(data))
		//{
		//	return false;
		//}

		//auto temp = mRoot;
		//bool bCheck = false;
		//std::shared_ptr<TreeNode<T>> before = mRoot;

		//if (*(mRoot->Data) == data && temp->Left == nullptr && temp->Right == nullptr)
		//{
		//	mRoot = nullptr;
		//	return true;
		//}

		//if (*(mRoot->Data) == data && temp->Right == nullptr)
		//{
		//	before = temp->Left;
		//	mRoot.reset();
		//	mRoot = temp->Left;
		//	return true;
		//}

		//if (*(mRoot->Data) == data && temp->Left == nullptr)
		//{
		//	before = temp->Right;
		//	mRoot.reset();
		//	mRoot = temp->Right;
		//	return true;
		//}

		//while (temp != nullptr)
		//{
		//	if (*(temp->Data) == data)
		//	{
		//		if (temp->Left == nullptr && temp->Right == nullptr)
		//		{
		//			if (bCheck)
		//			{
		//				before->Left = nullptr;
		//			}
		//			else
		//			{
		//				before->Right = nullptr;
		//			}
		//		}
		//		else if (temp->Left == nullptr || temp->Right == nullptr)
		//		{
		//			if (bCheck)
		//			{
		//				if (temp->Left == nullptr)
		//				{
		//					before->Left = temp->Right;
		//					temp->Right->Parent = before;
		//				}
		//				else
		//				{
		//					before->Left = temp->Left;
		//					temp->Left->Parent = before;
		//				}
		//			}
		//			else
		//			{
		//				if (temp->Left == nullptr)
		//				{
		//					before->Right = temp->Right;
		//					temp->Right->Parent = before;
		//				}
		//				else
		//				{
		//					before->Right = temp->Left;
		//					temp->Left->Parent = before;
		//				}
		//			}
		//		}
		//		else
		//		{
		//			auto ttemp = temp;
		//			auto ttemp2 = temp;
		//			temp = temp->Right;

		//			while (temp->Left != nullptr)
		//			{
		//				ttemp2 = temp;
		//				temp = temp->Left;
		//			}

		//			if (ttemp != ttemp2)
		//			{
		//				//std::cout << "asdasdsdf";
		//				if (temp->Right == nullptr)
		//				{
		//					temp->Left = ttemp->Left;
		//					temp->Right = ttemp->Right;
		//					ttemp->Left->Parent = temp;
		//					ttemp->Right->Parent = temp;
		//					//ttemp2->Left = nullptr;
		//				}
		//				else
		//				{
		//					auto r = temp->Right;
		//					
		//					while (r->Right != nullptr)
		//					{
		//						r = r->Right;
		//					}

		//					temp->Left = ttemp->Left;
		//					ttemp->Left->Parent = temp;
		//					r->Right = ttemp2;
		//					ttemp2->Parent = r;
		//					ttemp->Right = nullptr;
		//				}
		//			}
		//			else
		//			{
		//				temp->Left = ttemp->Left;
		//				ttemp->Left->Parent = temp;
		//				//std::cout << "asdasdsdf";
		//				if (mRoot == ttemp)
		//				{
		//					//std::cout << "xxx";
		//					mRoot = temp;
		//				}
		//				else
		//				{
		//					if (bCheck)
		//					{
		//						before->Left = nullptr;
		//					}
		//					else
		//					{
		//						before->Right = nullptr;
		//					}
		//				}
		//			}

		//			if (before != ttemp)
		//			{
		//				if (bCheck)
		//				{
		//					before->Left = temp;
		//					temp->Parent = before;
		//				}
		//				else
		//				{
		//					before->Right = temp;
		//					temp->Parent = before;
		//				}
		//			}
		//			else
		//			{
		//				mRoot = temp;
		//			}

		//			ttemp2->Left = nullptr;
		//		}

		//		return true;
		//	}
		//	else if (*(temp->Data) < data)
		//	{
		//		before = temp;
		//		temp = temp->Right;
		//		bCheck = false;
		//	}
		//	else if (*(temp->Data) > data)
		//	{
		//		before = temp;
		//		temp = temp->Left;
		//		bCheck = true;
		//	}
		//}

		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		v = Recurse(startNode, 0);

		return v;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::Recurse(const std::shared_ptr<TreeNode<T>> node, unsigned int i)
	{
		static std::vector<T> v;

		if (i == 0)
		{
			v.clear();
		}
	
		if (node == nullptr)
		{
			return v;
		}

		//std::cout << *node->Data;
		Recurse(node->Left, 1);
		v.push_back(*(node->Data));
		Recurse(node->Right, 1);

		return v;
	}
}