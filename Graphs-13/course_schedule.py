# https://www.youtube.com/watch?v=EgI5nU9etnU

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
    #  map each course for the prerequisites list. Creating adjoincy list
        preMap = {i:[] for i in range(numCourses)}

        for crs,  pre in prerequisites:
            preMap[crs].append(pre)

        #visit all nodes in current 
        visitSet = set()

        def dfs(crs):
            if crs in visitSet:
                return False

            if preMap[crs] == []:
                return True

            visitSet.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre): return False

            visitSet.remove(crs)

            preMap[crs] = []
            return True

        for crs in range(numCourses):
            if not dfs(crs): return False
        return True

            
        
