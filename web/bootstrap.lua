-- Apply Bootstrap table styling without requiring Bootstrap-specific markup in Markdown.
function Table(table)
  table.classes:insert("table")
  table.classes:insert("table-hover")
  table.classes:insert("align-middle")
  return pandoc.Div(table, pandoc.Attr("", {"table-responsive"}))
end
