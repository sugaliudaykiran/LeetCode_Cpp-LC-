for (int j=0; j<totalWordsLength; j++)
{
int wordIndex = i + j * eachWordLength;
string str = s.substr(wordIndex, eachWordLength);
cout << str << "\n";
if (frequencyMap[str] == 0)
{
break;
}
seenWord[str]++;
if (seenWord[str] > frequencyMap[str])
{
break;
}
if (j+1 == totalWordsLength)
{
res.push_back(i);
}
}
}
return res;
}
};
​