import bibtexparser
from urllib.request import urlopen

def clean_url(url):
    return url.replace('\_', '_')

def clean_title(text):
    return text.replace('\\textasteriskcentered', '\*')

meta_fields = ['data', 'slides', 'slides2', 'slides3', 'teaser', 'talk', "poster", "poster2", "code", "leaderboard", "project", "demo", "blog", "coverage", "visualization"]
output_list_map = {}

blackcolorbegin = "{{<font color=\"Black\">"
colorbegin = "{{<font color=\"DarkRed\">"
graycolorbegin = "{{<font color=\"Gray\">"
colorend = "</font>}}"
fontsizebegin = "{{<font size=-1>}}"
fontsizeend = "{{</font>}}"

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
    "Yejin Choi": "https://homes.cs.washington.edu/~yejin/",
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
    "Arda Uzunoglu": "https://scholar.google.com/citations?user=5fsB_GMAAAAJ",
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
}


bibtex_file = urlopen('https://raw.githubusercontent.com/danyaljj/bibfile/master/ref.bib')
bibtex_database = bibtexparser.loads( bibtex_file.read())

for x in bibtex_database.entries:
    # print(x)
    if 'khashabi' in x['author'].lower():
        print(x)
        x['title'] = x['title'].strip()
        if x['title'][-1] not in ['.', '?']:
            x['title'] += '.'

        if 'url' in x:
            title = f"[{clean_url(x['url'])} *{x['title']}*]"
        else:
            title = f"*{x['title']}*"
        title = clean_title(title)

        if "{" in title:
            title = title.replace("{", "").replace("}", "")

        authors = ""
        all_authors = x['author'].split(" and ")
        for idx, a in enumerate(all_authors):
            if ", " in a:
                asplit = a.split(", ")
                a = f"{asplit[1]} {asplit[0]}"

            # look up the author website
            if a in urls:
                # a = f"[{urls[a]} {a}]"
                a = f"[{urls[a]} {blackcolorbegin} {a}{colorend}]"
            # elif a.lower() in urls:
            #     # a = f"[{urls[a]} {a}]"
            #     a = f"[{urls[a.lower()]} {blackcolorbegin} {a}{colorend}]"


            if len(all_authors) == 1:
                authors = f"{a}."
            elif idx == len(all_authors) - 1:
                authors += f" and {a}."
            elif idx == 40:
                authors += f" and others."
                break
            else:
                if idx == 0:
                    authors += f"{a}"
                else:
                    authors += f", {a}"

        venue = ""
        if "journal" in x:
            venue = x['journal']
        elif "booktitle" in x:
            venue = x['booktitle']
        elif x["ENTRYTYPE"] == "phdthesis":
            venue = "PhD thesis at " + x['school']
        elif "note" in x:
            venue = x["note"]

        if "publisher" in x:
            venue += " - " + x["publisher"]

        if "\CNFX{" in venue:
            venue = venue.replace("\CNFX{", "(")
            venue = venue.replace("}", ")")

        if "arXiv preprint" in venue or "biorxiv preprint" in venue.lower():
            venue = f"{graycolorbegin}{venue}{colorend}"
        else:
            venue = f"{colorbegin}{venue}{colorend}"

        awards = " "
        if "awards" in x:
            x['awards'] = x['awards'].strip()
            if "." != x['awards'][-1]:
                x['awards'] += "."

            awards = f" *{x['awards']}* "

        meta_items = []
        # if 'url' in x and "https://arxiv.org/abs/" in x['url']:
            # ar5iv_url = x['url'].replace("https://arxiv.org/abs/", "https://ar5iv.labs.arxiv.org/html/")
            # meta_items.append(f"[{clean_url(ar5iv_url)} \[html\] ]")

        for meta_field in meta_fields:
            if meta_field.lower() in x:
                meta_items.append(f"[{clean_url(x[meta_field.lower()])} \[{meta_field}\] ]")

        if len(meta_items) > 0:
            meta_items = " ".join(meta_items)
        else:
            meta_items = ""

        if x['year'] not in output_list_map:
            output_list_map[x['year']] = []

        output_list_map[x['year']].append(
            f" \n - {title}  \\n    {authors} \\n   {venue}, {x['year']}.{awards}{fontsizebegin}{meta_items}{fontsizeend}\n"
        )


def rank_function(entry):
    entry = entry.lower()
    if "(emnlp)" in entry:
        return 2
    elif "(colm)" in entry:
        return 2.4
    elif "(neurips)" in entry:
        return 1
    elif  " acl" in entry and "workshop" in entry:
        return 3.5
    elif "(acl)" in entry:
        return 4
    elif "(naacl)" in entry:
        return 5
    elif "arxiv preprint" in entry or "biorxiv preprint" in entry.lower():
        # appears on top
        return 0
    else:
        # appears low
        return 6

output = "\n\n"
for year in sorted(output_list_map.keys(), reverse=True):
    print(" - - - -- - - - -")
    print(year)
    # sort them based on ranking function
    output_list_map[year] = sorted(reversed(output_list_map[year]), key=rank_function)
    print(output_list_map[year])
    output += "".join(output_list_map[year])
    print("".join(output_list_map[year]))

outputfile = open("publication.jemdoc", "w")
outputfile.write(output)