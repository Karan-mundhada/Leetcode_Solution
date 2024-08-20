class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for c in ransomNote:
            if c not in magazine:
                return False
            else:
                magazine = magazine.replace(c, "", 1)

        return True