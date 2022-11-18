/*

a very good question which teaches how to check if two lines overlap or not 
simply check if the minimum of the ends of two lines(end point of first line) - maximum of start points of two lines(start point of second line) >=0
if this value is negative than the two lines do not overlap
in case one line is inside other line, then, the whole line is selected using this formula.

*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      long area = (ax2-ax1)*(ay2-ay1);
      area+= (bx2-bx1)*(by2-by1);
      if(min(bx2,ax2)-max(ax1,bx1)>=0){
          if(min(by2,ay2)-max(by1,ay1)>=0){
              area-= abs(abs(min(bx2,ax2)-max(ax1,bx1))*(abs(min(by2,ay2)-max(by1,ay1))));
          }
      }
      return area;
    }
};
