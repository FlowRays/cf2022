1692H dp
1690G ds(stl: map/set)
    坑点：map只能用map::upper_bound()，不能用std::upper_bound，set两个都可以用，但是set::upper_bound更快，std会TLE
    tip：map/set::erase(it1,it2) [it1,it2)
        这两者的iterator不能做减法，只能自增自减，可以通过std::prev(it)获取前一个
1690F 小号比赛时做出的一道题 permutation cyle的思想 lcm
1689D 
    一道有点偏计算几何的题目，大体思路想出来了，但还是搞不定WA2，麻了，下次遇到这种直接看题解吧，不要在模糊而错误的思路上越走越远
    看了题解发现只需要想出main point之后暴力就可以了，而我想出main point之后试图通过O(1)的数学/几何解决，吐了
1689C 同样是小号比赛时做的一道题，赛时还没做出来，赛后几分钟A了，就是树形dp，1600/1700挺常见的题了
    再次做了一遍居然一下不知道怎么做了，甚至看完当时AC的代码都有些看不懂，以为是印象中的某一题，然后就按着印象中的思路去写了，也没好好去想
