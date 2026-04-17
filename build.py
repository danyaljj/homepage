"""Assembles index.html from index_source.html + publications.html."""

with open('index_source.html', 'r') as f:
    template = f.read()

try:
    with open('publications.html', 'r') as f:
        publications = f.read()
except FileNotFoundError:
    publications = '<p><em>Publications not yet generated. Run bibtex2html_html.py first.</em></p>'

output = template.replace('<!-- PUBLICATIONS_PLACEHOLDER -->', publications)

with open('index.html', 'w') as f:
    f.write(output)

print('Built index.html')
