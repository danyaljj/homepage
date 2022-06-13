import bibtexparser
from urllib.request import urlopen

# def customizations(record):
#     record = bibtexparser.customization.splitname(record)
#     return record
# parser = BibTexParser()
# parser.customization = customizations
# parser.ignore_nonstandard_types = False
# parser.homogenize_fields = False
# parser.common_strings = False

def clean_url(url):
    return url.replace('\_', '_')

def clean_title(text):
    return text.replace('\\textasteriskcentered', '\*')

meta_fields = ['data', 'slides', 'talk', "poster", "code", "leaderboard", "project", "demo", "blog", "coverage", "visualization"]
output = "\n\n"
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
        else:
            venue = x["note"]

        if "publisher" in x:
            venue += " - " + x["publisher"]

        if "\CNFX{" in venue:
            venue = venue.replace("\CNFX{", "(")
            venue = venue.replace("}", ")")

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
        output = f" \n - {title}  \\n    {authors} \\n    {colorbegin}{venue}{colorend}, {x['year']}. {fontsizebegin}{meta_items}{fontsizeend}\n" + output


print(output)

outputfile = open("publication.jemdoc", "w")
outputfile.write(output)