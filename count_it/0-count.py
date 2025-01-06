#!/usr/bin/python3
"""Module Reddit
"""
import requests
import re


def count_words(subreddit, word_list, after=None, counts=None):
    """Queries the reddit API for hot articles
    """
    if counts is None:
        counts = {}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {"after": after}
    headers = {"User-agent": "Python3:reddit:1.0 (by /u/holberton_school)"}

    try:
        response = requests.get(
            url,
            param=params,
            headers=headers,
            allow_redirects=False)
        if response.status_code != 200:
            return
        data = response.json()
        for post in data['data']['children']:
            title = post['data']['title']

            clean_title = re.sub(r'[^a-zA-Z\s]', ' ', title.lower())
            words = clean_title.split()

            for word in words:
                if word in counts:
                    counts[word] += 1

        after = data['data'].get('after')
        if after:
            count_words(subreddit, word_list, after, counts)
        else:
            sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
            for word, count in sorted_counts:
                if count > 0:
                    print(f"{word} {count}")

    except Exception as e:
        return
