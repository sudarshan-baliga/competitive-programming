# https://www.codechef.com/JUNE18B/problems/SHKSTR

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEndOfWord = False
class Trie:
    def __init__(self):
        self.root = TrieNode()

    def _getIndex(self,ch):
        return ord(ch) - ord('a')

    def insert(self, key):
        crawl = self.root
        length = len(key)
        for ch in range(length):
            index = self._getIndex(key[ch])
            if not crawl.children[index]:
                crawl.children[index] = TrieNode()
            crawl = crawl.children[index]
        crawl.isEndOfWord = True

    def search(self, key):
        crawl = self.root
        length = len(key)
        didnotend = True
        for ch in range(length):
            index = self._getIndex(key[ch])
            curr = ch
            if not crawl.children[index]:
                # return false
                didnotend = True
                while(didnotend):
                    didnotend = False
                    for index, ele in enumerate(crawl.children):
                        if(ele == None):
                            continue
                        print(chr(index + 97), end = '')
                        crawl = crawl.children[index]
                        didnotend = True
                        break
                    if(not didnotend):
                        break
            else:
                print(key[ch], end = '')
                crawl = crawl.children[index]
            if(not didnotend):
                print()
                break
        # return crawl != None and crawl.isEndOfWord
def main():
    keys = ["the","a","there","anaswerrra","any",
            "by","their"]
    t = Trie()
    for key in keys:
        t.insert(key)
    t.search("ansfdfdsfdsfdsfds")
    t.search("ab")
if __name__ == '__main__':
    main()
