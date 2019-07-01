import React from "react"
import { graphql } from "gatsby"
const Layout = require('../components/layout/Layout.bs.js').make;

export default ({ data }) => {
  console.log(data);
  return < Layout showLangSwitch lang='fr' >
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
