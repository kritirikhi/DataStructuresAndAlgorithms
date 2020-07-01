//                                                              QUESTION ON LEETCODE


// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.

// Example 1:
// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.



class Solution {
public:
    void fillcolor(vector<vector<int>>& image,int i,int j,int color,int newColor,int r,int c){
        if(i<0 || j<0 || i>=r || j>=c){
            return;
        }
        
        if(image[i][j]!=color){
            return;
        }
        
        image[i][j]=newColor;
        
        fillcolor(image,i+1,j,color,newColor,r,c);
        fillcolor(image,i-1,j,color,newColor,r,c);
        fillcolor(image,i,j+1,color,newColor,r,c);
        fillcolor(image,i,j-1,color,newColor,r,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor){
            return image;
        }
        int r=image.size();
        int c=image[0].size();
        cout<<r<<c;
        fillcolor(image,sr,sc,image[sr][sc],newColor,r,c);
        return image;
    }
};