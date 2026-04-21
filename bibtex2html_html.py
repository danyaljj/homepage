import bibtexparser
from urllib.request import urlopen
import html as html_module

def clean_url(url):
    return url.replace('\\_', '_')

def clean_title(text):
    return text.replace('\\textasteriskcentered', '*')

meta_fields = ['data', 'slides', 'slides2', 'slides3', 'teaser', 'talk', 'poster', 'poster2',
               'code', 'leaderboard', 'project', 'demo', 'blog', 'coverage', 'visualization']

urls = {
    "Yining Lu": "https://yining610.github.io/",
    "Daniel Khashabi": "https://www.cs.jhu.edu/~danielk/",
    "Zhengping Jiang": "https://zipjiang.github.io/",
    "Jingyu Zhang": "https://jackz.io/",
    "Nathaniel Weir": "https://nweir127.github.io/",
    "Benjamin Van Durme": "https://www.cs.jhu.edu/~vandurme/index.html",
    "Anqi Liu": "https://anqiliu-ai.github.io/",
    "Alan Yuille": "https://www.cs.jhu.edu/~ayuille/",
    "Jieneng Chen": "https://beckschen.github.io/",
    "Lingfeng Shen": "https://shadowkiller33.github.io/",
    "Dongwei Jiang": "https://jiangdongwei.com/",
    "Jiefu Ou": "https://jefferyo.github.io/",
    "Nicholas Andrews": "https://www.cs.jhu.edu/~noa/",
    "Andrew Wang": "https://scholar.google.com/citations?user=clTRNPsAAAAJ&hl=en",
    "Weiting Tan": "https://steventan0110.github.io/",
    "Haoran Xu": "https://www.fe1ixxu.com/",
    "Kenton Murray": "https://kentonmurray.com/index.html",
    "Abe Bohan Hou": "https://nlp4policy.notion.site/Abe-Hou-21661aa32a7a4d19a45b5bf31c11a99e",
    "Tianjian Li": "https://tianjianl.github.io/",
    "Orion Weller": "https://orionweller.github.io/",
    "Marc Marone": "https://marcmarone.com/",
    "Hannaneh Hajishirzi": "https://homes.cs.washington.edu/~hannaneh/",
    "Kai-Wei Chang": "https://web.cs.ucla.edu/~kwchang/",
    "Yejin Choi": "https://yejinc.github.io/",
    "Maarten Sap": "https://maartensap.com/",
    "Noah A. Smith": "https://nasmith.github.io/",
    "Noah A Smith": "https://nasmith.github.io/",
    "Philipp Koehn": "https://www.cs.jhu.edu/~phi/",
    "Dan Roth": "https://www.cis.upenn.edu/~danroth/",
    "Ashish Sabharwal": "https://allenai.org/team/ashishs",
    "Tushar Khot": "https://allenai.org/team/tushark",
    "Tianxiao Shen": "https://shentianxiao.github.io/",
    "Daniel S Weld": "https://allenai.org/team/danw",
    "Chris Callison-Burch": "https://www.cis.upenn.edu/~ccb/",
    "Peter Clark": "https://allenai.org/team/peterc",
    "Oren Etzioni": "https://allenai.org/team/orene",
    "Candice Penelton": "https://candice-morgan.github.io/",
    "Candice Morgan": "https://candice-morgan.github.io/",
    "Arda Uzunoğlu": "https://scholar.google.com/citations?user=5fsB_GMAAAAJ",
    "Aayush Mishra": "https://aamixsh.github.io/",
    "Adam Byerly": "https://scholar.google.com/citations?user=t3Hhnx8AAAAJ&hl=en",
    "Sihao Chen": "https://www.seas.upenn.edu/~sihaoc/",
    "Ben Zhou": "http://xuanyu.me/",
    "Christos Christodoulopoulos": "https://christos-c.com/",
    "Kent Quanrud": "https://www.kentquanrud.com/",
    "Sameer Singh": "https://sameersingh.org/",
    "Tianmin Shu": "https://www.tshu.io/",
    "Yizhong Wang": "https://homes.cs.washington.edu/~yizhongw/",
    "Yeganeh Kordi": "https://yeganehkordi.github.io/",
    "Swaroop Mishra": "https://swarooprm.github.io/",
    "Sean Welleck": "https://wellecks.com/",
    "Lianhui Qin": "https://lianhui.ucsd.edu/",
    "Sewon Min": "https://www.sewonmin.com/",
    "Rama Chellappa": "https://engineering.jhu.edu/faculty/rama-chellappa/",
    "Taiming Lu": "https://taiminglu.com/",
    "Faraz Faghri": "https://scholar.google.com/citations?user=Rr643xYAAAAJ&hl=en",
    "Mike A. Nalls": "https://scholar.google.com/citations?user=ZjfgPLMAAAAJ&hl=en",
    "Tianxing He": "https://cloudygoose.github.io/",
    "Hanjie Chen": "https://hanjiechen.github.io/",
    "Yulia Tsvetkov": "https://homes.cs.washington.edu/~yuliats/",
    "Peter West": "https://peterwestai.notion.site/",
    "William Gantt Walden": "https://wgantt.github.io/personal-website/",
    "Niyati Bafna": "https://niyatibafna.github.io/",
    "David Yarowsky": "https://www.cs.jhu.edu/~yarowsky/",
    "Weiqi Wang": "https://mighty-weaver.github.io/",
    "Sungwon Kim": "https://sungwon-kim.com/",
    "Isabel Cachola": "https://isabelcachola.com/",
    "Zhouxiang Fang": "https://zhouxiangfang.github.io/",
    "Kate Sanders": "https://katesanders9.github.io/",
    "Alvin Zhang": "https://scholar.google.com/citations?user=BLkk5kYAAAAJ",
    "William Jurayj": "https://williamjurayj.com/",
    "Eric Nalisnick": "https://enalisnick.github.io/",
    "Jason Weston": "https://scholar.google.com/citations?hl=en&user=lMkTx0EAAAAJ",
    "Dawn Lawrie ": "https://scholar.google.com/citations?user=Ij9zwyoAAAAJ&hl=en",
    "Kevin Duh": "https://scholar.google.com/citations?user=M3BSiiQAAAAJ&hl=en",
    "Eugene Yang": "https://scholar.google.com/citations?user=JVqgs4gAAAAJ&hl=en&oi=ao",
    "Faeze Brahman": "https://fabrahman.github.io/",
    "Jeffrey Cheng": "https://nexync.github.io/",
    "Xiang Lorraine Li": "https://lorraine333.github.io/",
    "Ximing Lu": "https://gloriaximinglu.github.io/",
    "Yilun Du": "https://yilundu.github.io/",
    "Yangqiu Song": "https://www.cse.ust.hk/~yqsong/",
    "Andrea Wynn": "https://andreawynn.github.io/",
    "Meng Jiang": "http://www.meng-jiang.com/",
    "Lauren Gardner": "https://engineering.jhu.edu/case/faculty/lauren-gardner/",
    "Michael C. Schatz": "https://schatz-lab.org/",
    "Nathan Breslow": "https://github.com/N8python",
    "Dawn Lawrie": "https://hltcoe.jhu.edu/researcher/dawn-lawrie/",
    "Victor Zhong": "https://www.victorzhong.com/",
    "Akari Asai": "https://akariasai.github.io/",
    "Muhan Gao": "https://muhan-gao.com/",
    "Mark Dredze": "https://www.cs.jhu.edu/~mdredze/",
    "Chunsheng Zuo": "https://scholar.google.com/citations?user=Uy79AH0AAAAJ&hl=en",
    "Mehrdad Farajtabar": "https://sites.google.com/view/mehrdad",
    "Xi Wang": "https://scholar.google.com/citations?user=giztudUAAAAJ&hl=en",
    "Chien-Ming Huang": "https://www.cs.jhu.edu/~cmhuang/",
    "Hannah Collison": "https://isgla.github.io/",
    "Zheyuan Zhang": "https://zheyuanzhang.me/",
    "Tianlu Wang": "https://tianlu-wang.github.io/",
}

SELF_AUTHOR = "Daniel Khashabi"

def is_selected(entry):
    """A paper is 'selected' if its 'tags' field contains 'selected'."""
    tags = entry.get('tags', '')
    return 'selected' in tags.lower()


# Canonical topic labels and their CSS slugs
TOPIC_LABELS = [
    'Safety',
    'Interpretability',
    'Reasoning',
    'Agents',
    'Retrieval',
    'Evaluation',
    'AI for Science',
    'Multilingual',
    'AI + Humans',
    'Embodied',
    'Multimodal',
    'Long-context',
    'Grounding',
    'Model Training',
]

TOPIC_SLUG = {
    'Safety':             'safety',
    'Interpretability':   'interpretability',
    'Reasoning':          'reasoning',
    'Agents':             'agents',
    'Retrieval':          'retrieval',
    'Evaluation':         'evaluation',
    'AI for Science':     'ai-for-science',
    'Multilingual':       'multilinguality',
    'AI + Humans':        'social-impact',
    'Embodied':           'embodied',
    'Multimodal':         'multimodal',
    'Long-context':       'long-context',
    'Grounding':          'grounding',
    'Model Training':     'training',
}

# Maps old/alternative bib tag values to canonical labels
TOPIC_ALIASES = {
    'training':          'Model Training',
    'multilinguality':   'Multilingual',
    'social impact':     'AI + Humans',
    'alignment & safety': 'Safety',
}

def parse_topics(entry):
    """Extract canonical topic labels from the 'tags' bib field."""
    tags_str = entry.get('tags', '')
    raw_tags = [t.strip() for t in tags_str.split(',')]
    topics = []
    for raw in raw_tags:
        raw_lower = raw.lower()
        matched = False
        for label in TOPIC_LABELS:
            if raw_lower == label.lower():
                topics.append(label)
                matched = True
                break
        if not matched and raw_lower in TOPIC_ALIASES:
            topics.append(TOPIC_ALIASES[raw_lower])
    return topics

bibtex_file = urlopen('https://raw.githubusercontent.com/danyaljj/bibfile/master/ref.bib')
bibtex_database = bibtexparser.loads(bibtex_file.read())

output_list_map = {}

for x in bibtex_database.entries:
    if 'khashabi' not in x['author'].lower():
        continue

    print(x)

    x['title'] = x['title'].strip()
    if x['title'][-1] not in ['.', '?']:
        x['title'] += '.'

    title = clean_title(x['title'])
    title = title.replace('``', '\u201c').replace("''", '\u201d')
    title = title.replace('{', '').replace('}', '')
    title_escaped = html_module.escape(title)

    if 'url' in x:
        url = clean_url(x['url'])
        title_html = f'<a href="{url}">{title_escaped}</a>'
    else:
        title_html = title_escaped

    # Authors
    all_authors = x['author'].split(' and ')
    author_parts = []
    for idx, a in enumerate(all_authors):
        if ', ' in a:
            asplit = a.split(', ')
            a = f'{asplit[1]} {asplit[0]}'

        a_stripped = a.strip()
        a_escaped = html_module.escape(a_stripped)

        if a_stripped == SELF_AUTHOR:
            if a_stripped in urls:
                author_parts.append(
                    f'<a href="{urls[a_stripped]}" class="pub-self">{a_escaped}</a>'
                )
            else:
                author_parts.append(f'<span class="pub-self">{a_escaped}</span>')
        elif a_stripped in urls:
            author_parts.append(f'<a href="{urls[a_stripped]}">{a_escaped}</a>')
        else:
            author_parts.append(a_escaped)

        if idx == 40:
            author_parts.append('and others')
            break

    if len(author_parts) == 1:
        authors_html = author_parts[0]
    elif len(author_parts) == 2:
        authors_html = f'{author_parts[0]} and {author_parts[1]}'
    else:
        authors_html = ', '.join(author_parts[:-1]) + f', and {author_parts[-1]}'

    # Venue
    venue = ''
    if 'journal' in x:
        venue = x['journal']
    elif 'booktitle' in x:
        venue = x['booktitle']
    elif x['ENTRYTYPE'] == 'phdthesis':
        venue = 'PhD thesis at ' + x['school']
    elif 'note' in x:
        venue = x['note']

    if 'publisher' in x:
        venue += ' - ' + x['publisher']

    if '\\CNFX{' in venue:
        venue = venue.replace('\\CNFX{', '(').replace('}', ')')

    venue_escaped = html_module.escape(venue.strip())
    is_preprint = 'arxiv preprint' in venue.lower() or 'biorxiv preprint' in venue.lower()
    venue_class = 'venue-preprint' if is_preprint else 'venue-conf'
    venue_html = f'<span class="{venue_class}">{venue_escaped}</span>'

    # Awards
    awards_html = ''
    if 'awards' in x:
        award_text = x['awards'].strip().replace('\\%', '%')
        if award_text[-1] != '.':
            award_text += '.'
        award_escaped = html_module.escape(award_text)
        emoji = '&#x1F3C6; ' if 'award' in award_text.lower() else ''
        awards_html = f' <span class="pub-award">{emoji}{award_escaped}</span>'

    # Meta links
    link_items = []
    for field in meta_fields:
        if field.lower() in x:
            link_url = clean_url(x[field.lower()])
            link_items.append(f'<a href="{link_url}" class="pub-link">[{field}]</a>')

    links_html = ''
    if link_items:
        links_html = ' <span class="pub-links">' + ''.join(link_items) + '</span>'

    selected = is_selected(x)
    topics = parse_topics(x)
    topic_badges_html = ''.join(
        f'<span class="topic-badge topic-{TOPIC_SLUG[t]}">{t}</span>' for t in topics
    )

    tags_span = f'<span class="pub-title-tags">{topic_badges_html}</span>' if topic_badges_html else ''
    topics_attr = ' '.join(TOPIC_SLUG[t] for t in topics)
    entry_html = (
        f'    <li class="pub-entry" data-year="{x["year"]}" data-selected="{str(selected).lower()}" data-topics="{topics_attr}">\n'
        f'      <div class="pub-title"><span class="pub-title-text">{title_html}</span>{tags_span}</div>\n'
        f'      <div class="pub-authors">{authors_html}</div>\n'
        f'      <div class="pub-meta">{venue_html}, {x["year"]}.{awards_html}{links_html}</div>\n'
        f'    </li>'
    )

    year = x['year']
    if year not in output_list_map:
        output_list_map[year] = []
    output_list_map[year].append(entry_html)


def rank_function(entry):
    e = entry.lower()
    if '(emnlp)' in e:
        return 2
    elif '(tmlr)' in e:
        return 0.7
    elif '(eacl)' in e:
        return 0.9
    elif '(iclr)' in e:
        return 0.8
    elif '(colm)' in e:
        return 2.4
    elif '(aacl)' in e:
        return 0.9
    elif '(neurips)' in e:
        return 1
    elif ' acl' in e and 'workshop' in e:
        return 3.5
    elif '(acl)' in e:
        return 4
    elif '(naacl)' in e:
        return 5
    elif '(icml)' in e:
        return 4.1
    elif 'arxiv preprint' in e or 'biorxiv' in e:
        return 0
    else:
        return 6


output_parts = []
for year in sorted(output_list_map.keys(), reverse=True):
    sorted_entries = sorted(reversed(output_list_map[year]), key=rank_function)
    entries_html = '\n'.join(sorted_entries)
    output_parts.append(
        f'<div class="pub-year-group">\n'
        f'  <div class="pub-year">{year}</div>\n'
        f'  <ul class="pub-list">\n'
        f'{entries_html}\n'
        f'  </ul>\n'
        f'</div>'
    )

output = '\n\n'.join(output_parts)

with open('publications.html', 'w') as f:
    f.write(output)

print('Generated publications.html')
