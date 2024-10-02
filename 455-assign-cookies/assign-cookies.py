class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        r=0
        pt1=0
        pt2=0
        while pt2<len(s):
            if not pt1<len(g):
                break
            if g[pt1]<=s[pt2]:
                r+=1
                pt1+=1
                pt2+=1
            else:
                pt2+=1
        return r
