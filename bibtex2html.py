import bibtexparser
from urllib.request import urlopen

def clean_url(url):
    return url.replace('\_', '_')

def clean_title(text):
    return text.replace('\\textasteriskcentered', '\*')

meta_fields = ['data', 'slides', 'slides2', 'slides3', 'talk', "poster", "poster2", "code", "leaderboard", "project", "demo", "blog", "coverage", "visualization"]
output_list_map = {}


bibtex_file = urlopen('https://raw.githubusercontent.com/danyaljj/bibfile/master/ref.bib')
bibtex_database = bibtexparser.loads( bibtex_file.read())

for x in bibtex_database.entries:
    print(x)
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

        if "," in x['author']:
            authors = ""
            all_authors = x['author'].split(" and ")
            for idx, a in enumerate(all_authors):
                if ", " in a:
                    asplit = a.split(", ")
                    a = f"{asplit[1]} {asplit[0]}"
                if idx == len(all_authors) - 1:
                    authors += f" and {a}."
                elif idx == 40:
                    authors += f" and others."
                    break
                else:
                    if idx == 0:
                        authors += f"{a}"
                    else:
                        authors += f", {a}"
        else:
            authors = x['author']


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

        awards = " "
        if "awards" in x:
            x['awards'] = x['awards'].strip()
            if "." != x['awards'][-1]:
                x['awards'] += "."

            awards = f" *{x['awards']}* "

        meta_items = []
        for meta_field in meta_fields:
            if meta_field.lower() in x:
                meta_items.append(f"[{clean_url(x[meta_field.lower()])} \[{meta_field}\] ]")
        if len(meta_items) > 0:
            meta_items = " ".join(meta_items)
        else:
            meta_items = ""
        colorbegin = "{{<font color=\"DarkRed\">"
        colorend = "</font>}}"
        fontsizebegin = "{{<font size=-1>}}"
        fontsizeend = "{{</font>}}"

        if x['year'] not in output_list_map:
            output_list_map[x['year']] = []
        output_list_map[x['year']].append(
            f" \n - {title}  \\n    {authors} \\n    {colorbegin}{venue}{colorend}, {x['year']}.{awards}{fontsizebegin}{meta_items}{fontsizeend}\n"
        )


def rank_function(entry):
    entry = entry.lower()
    if "(emnlp)" in entry:
        return 1
    elif "(neurips)" in entry:
        return 2
    elif "(naacl)" in entry:
        return 3
    elif "(acl)" in entry:
        return 4
    elif "arxiv preprint" in entry:
        return 0
    else:
        return 5

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