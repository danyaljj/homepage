python3 bibtex2html_html.py      # fetch bib → publications.html
python3 build.py                  # template + publications → index.html
scp index.html masters1:/users/danielk/public_html
scp style_modern.css masters1:/users/danielk/public_html
#ssh masters1 "chmod 644 /users/danielk/public_html/index.html /users/danielk/public_html/style_modern.css"
# scp publications.html masters1:/users/danielk/public_html
# scp -r files/* masters1:/users/danielk/public_html
# scp -r files/2024_quote_tuning masters1:/users/danielk/public_html/files/
# scp -r * masters1:/users/danielk/public_html
