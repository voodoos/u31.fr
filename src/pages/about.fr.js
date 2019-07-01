import React from "react"
import { graphql } from "gatsby"
const Layout = require('../components/layout/Layout.bs.js').make;
const Global = require('../Global.bs.js')

console.log(Global);
Global.set_lang_fr();

export default ({ data }) => {
  console.log(data);
  return < Layout showLangSwitch >
    <div dangerouslySetInnerHTML=
      {{ __html: data.page.nodes[0].childMarkdownRemark.html }} />
  </Layout >
}

export const query = graphql`
query {
  page: allFile(filter: {sourceInstanceName: {eq: "pages"}, name: {eq: "about.fr"}}) {
    nodes {
      childMarkdownRemark {
        html
      }
    }
  }
}
`
